TARGET = morse
CFLAGS = -g -Wall
OBJS = morse.o hw5.o
LIBS = -lm

all: ${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean:
	rm -f ${TARGET} ${OBJS}
