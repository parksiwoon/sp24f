#정적 및 동적 라이브러리를 각각 빌드할 수 있도록 구성
SRCS = main.c
LIBSRCS = open.c close.c put.c get.c
TARG_STATIC = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LSO = libkvs.so

all: static dynamic

static: $(TARG_STATIC)

$(TARG_STATIC): $(OBJS) $(LARS)
	$(CC) -o $(TARG_STATIC) $(OBJS) $(LIBS) -static

$(LARS): $(LOBJS)
	ar rs $(LARS) $(LOBJS)

dynamic: $(TARG_DYNAMIC)

$(TARG_DYNAMIC): $(OBJS) $(LSO)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) $(LIBS)

$(LSO): $(LIBSRCS)
	$(CC) -shared -o $(LSO) $(LIBSRCS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(LSO) $(TARG_STATIC) $(TARG_DYNAMIC)
