.PHONY: keypair

PWD = $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
SERVICEPATH = $(PWD)/webservice

create-keypair:
	@echo "Creating an rsa 256 key pair"
	openssl genpkey -algorithm RSA -out $(SERVICEPATH)/rsa_private_$(ENV).pem -pkeyopt rsa_keygen_bits:2048
	openssl rsa -in $(SERVICEPATH)/rsa_private_$(ENV).pem -pubout -out $(SERVICEPATH)/rsa_public_$(ENV).pem