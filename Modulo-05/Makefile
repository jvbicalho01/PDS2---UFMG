CC=g++
CFLAGS=-std=c++11 -Wall

BUILD= ./build
INCLUDE= ./include
ENTIDADES= ./src/entidades
SRC = ./src

all:vpl_execution

${BUILD}/Professor.o: ${INCLUDE}/Professor.hpp ${ENTIDADES}/Professor.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Professor.cpp -o ${BUILD}/Professor.o

${BUILD}/Funcionario.o: ${INCLUDE}/Funcionario.hpp ${ENTIDADES}/Funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Funcionario.cpp -o ${BUILD}/Funcionario.o

${BUILD}/Pessoa.o: ${INCLUDE}/Pessoa.hpp ${ENTIDADES}/Pessoa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${ENTIDADES}/Pessoa.cpp -o ${BUILD}/Pessoa.o

${BUILD}/main.o: ./src/main.cpp ${INCLUDE}/Professor.hpp ${INCLUDE}/Funcionario.hpp ${INCLUDE}/Pessoa.hpp
	${CC} ${CFLAGS} -I ${INCLUDE} -c ${SRC}/main.cpp -o ${BUILD}/main.o

vpl_execution: ${BUILD}/main.o ${BUILD}/Professor.o ${BUILD}/Funcionario.o ${BUILD}/Pessoa.o
	${CC} ${CFLAGS} -o vpl_execution ${BUILD}/main.o ${BUILD}/Professor.o ${BUILD}/Funcionario.o ${BUILD}/Pessoa.o

clean:
	rm -f main ${BUILD}/*.o