debug_flags=-ggdb -Wall -fpermissive -Wunused-function
standart_flag=-std=c++17
libs=-lncurses -lpthread
source=src/
objects=bin/obj/
program=bin/

all: clean main

main: Fork.o Philosopher.o Window.o Main.o 
	@echo "Generate binary, output is in ${program}, names Philosophers"
	@g++ ${objects}Main.o ${pbjects}Philosopher.o ${objects}Fork.o ${objects}Window.o -o ${program}Philosophers ${standart_flag} ${libs} ${debug_flags}

Main.o: ${source}Main.cpp
	@echo "Compile main"
	@g++ ${source}Main.cpp -c -o ${objects}Main.o ${debug_flags} ${libs} ${standart_flag} 

Window.o: ${source}Window.cpp
	@echo "Compile class Window"
	@g++ ${source}Window.cpp -c -o ${objects}Window.o ${debug_flags} ${standart_flag} 

Fork.o: ${source}Fork.cpp
	@echo "Compile class Fork"
	@g++ ${source}Fork.cpp -c -o ${objects}Fork.o ${debug_flags} ${standart_flag} 

Philosopher.o: ${source}Philosopher.cpp
	@echo "Compile class Philosopher"
	@g++ ${source}Philosopher.cpp -c -o ${objects}Philosopher.o ${debug_flags} ${standart_flag} 

clean:
	@echo "Clear obj files and binary"
	@rm -f ${objects}* bin/Philosophers