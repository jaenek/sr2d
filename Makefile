# Single compilation unit makefile
CC=g++
SDLINC = `sdl2-config --cflags`
SDLLIB = `sdl2-config --libs`
INCS = -I. ${SDLINC}
LIBS = -lm ${SDLLIB}
CFLAGS = -std=c++17 -g3 -Wall ${INCS}
LDFLAGS = ${LIBS}

.PHONY: all
all: options
	${CC} -o game game.cpp ${CFLAGS} ${LDFLAGS}

options:
	@echo sr2d build options:
	@echo "CC       = ${CC}"
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"

