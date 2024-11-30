all: main moon

main: main.c
	cc main.c -o main -lraylib -lm

moon: moon.c
	cc moon.c -o moon -lraylib -lm