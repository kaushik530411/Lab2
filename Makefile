# Makefile for Intro to Processes implementation.

list: main.c
	gcc -o main MAIN.c
	
clean:
	rm main