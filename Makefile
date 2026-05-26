CC=gcc
CFLAGS= --std=c99 -Wall -Wextra -g -lm
LDFLAGS= -lraylib -lm -lGL -lpthread -ldl -lrt -lX11

all: main.c
	${CC} ${CFLAGS} main.c -o raycaster ${LDFLAGS}

run:
	./raycaster


# default:
	# gcc main.c -o raycaster --std=c99 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -Wall -Wextra -pedantic-errors 

