package main

import (
	"context"
	"fmt"
	"log"
	"os"

	"github.com/jmoiron/sqlx"
	_ "github.com/lib/pq"
	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
)

type dataSources struct {
	postgreDB *sqlx.DB
	mongoDB   *mongo.Client
}

func initDS() (*dataSources, error) {
	log.Printf("Initializing data sources\n")
	//PostgreSQL
	pgHost := os.Getenv("PG_HOST")
	pgPort := os.Getenv("PG_PORT")
	pgUser := os.Getenv("PG_USER")
	pgPassword := os.Getenv("PG_PASSWORD")
	pgDB := os.Getenv("PG_DB")
	pgSSL := os.Getenv("PG_SSL")

	pgConnString := fmt.Sprintf("host=%s port=%s user=%s password=%s dbname=%s sslmode=%s", pgHost, pgPort, pgUser, pgPassword, pgDB, pgSSL)

	log.Printf("Connecting to Postgresql\n")
	db, err := sqlx.Open("postgres", pgConnString)

	if err != nil {
		return nil, fmt.Errorf("error opening postgre db: %w", err)
	}

	if err := db.Ping(); err != nil {
		return nil, fmt.Errorf("error connecting to postgre db: %w", err)
	}

	//MongoDb
	serverAPI := options.ServerAPI(options.ServerAPIVersion1)
	opts := options.Client().ApplyURI("").SetServerAPIOptions(serverAPI)
	client, err := mongo.Connect(context.TODO(), opts)
	if err != nil {
		return nil, fmt.Errorf("error connecting to mongo db: %w", err)
	}
	err = client.Ping(context.TODO(), nil)
	if err != nil {
		return nil, fmt.Errorf("error connecting to mongo db: %w", err)
	}
	log.Printf("Pinged your deployment. You successfully connected to MongoDB!\n")

	return &dataSources{
		postgreDB: db,
		mongoDB:   client,
	}, nil
}

func (d *dataSources) close() error {
	if err := d.postgreDB.Close(); err != nil {
		return fmt.Errorf("error closing Postgresql: %w", err)
	}

	if err := d.mongoDB.Disconnect(context.TODO()); err != nil {
		return fmt.Errorf("error closing MongoDb: %w", err)
	}

	return nil
}
