FROM golang:alpine as builder

WORKDIR /app
ENV GO111MODULE=on

COPY go.mod .
COPY go.sum .

RUN go mod download

COPY . .

RUN go build -o go-runner .

EXPOSE 8090 4000
CMD ["/app/go-runner"]