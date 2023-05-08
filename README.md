Just for syncing!!
Sync leet code problems :#

1. Setup host

c:\windows\system32\drivers\etc\hosts
-- Add domain
-- 127.0.0.1 blinkcat.programming

2. Gen rsa key
   cd to root

openssl genpkey -algorithm RSA -out ./webservice/rsa*private*test.pem -pkeyopt rsa_keygen_bits:2048
openssl rsa -in ./webservice/rsa_private_test.pem -pubout -out ./webservice/rsa*public*test.pem
