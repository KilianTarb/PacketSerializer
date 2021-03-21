CC = g++

INCLUDEFLAGS = -Iinclude
OUTFLAGS = -o build/
FLAGS = -std=c++17

all: 
	${CC} -c lib/PacketSerializer.cpp ${INCLUDEFLAGS} ${FLAGS} ${OUTFLAGS}PacketSerializer.o
	${CC} -c main.cpp ${INCLUDEFLAGS} ${FLAGS} ${OUTFLAGS}main.o
	${CC} build/*  ${SSLFLAGS} ${FLAGS} ${OUTFLAGS}packet_serializer

clean:
	rm build/*