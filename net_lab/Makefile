# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Targets
SERVER = server
CLIENT = client
SRCS = echoserver.c echoclient.c

# Rules
all: $(SERVER) $(CLIENT)

$(SERVER): echoserver.c
	$(CC) $(CFLAGS) -o $(SERVER) echoserver.c

$(CLIENT): echoclient.c
	$(CC) $(CFLAGS) -o $(CLIENT) echoclient.c

clean:
	rm -f $(SERVER) $(CLIENT)
