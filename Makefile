# Single compilation unit makefile
CC=g++
SDLINC = `sdl2-config --cflags`
SDLLIB = `sdl2-config --libs`
INCS = -I. ${SDLINC}
LIBS = -lm ${SDLLIB}
CFLAGS = -std=c++17 -g -Wall ${INCS}
LDFLAGS = -s ${LIBS}

.PHONY: all options clean run

all: options clean sr2d run

options:
	@echo sr2d build options:
	@echo "CC       = ${CC}"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"

clean:
	@echo cleaning
	@rm -f sr2d

sr2d: ${OBJ}
	${CC} -o $@ $@.cpp ${CFLAGS} ${LDFLAGS}

run:
	@./sr2d
