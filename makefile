all: main

main:
	gcc casa2d.c -o casa2d -lm -lGL -lGLU -lglut

clean:
	rm casa2d