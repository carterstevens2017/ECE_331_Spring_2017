TARGET = morse
OBJS = morse.o hw5.o
CFLAGS = -g -Wall
LIBS = -lm

.PHONY: all clean

all: ${TARGET}
${TARGET}: ${OBJS}
	${CC} -o ${TARGET} ${OBJS} ${LIBS}

clean:
	rm -f ${TARGET} ${OBJS}
