https://makefiletutorial.com/

targets: prerequisites
	command
	command
	command

main: main.c calc ui
	gcc main.c -o main

calc: calc.c add sub div mul
    gcc calc.c -o calc

add: add.c math.h
    gcc add.c -o add
