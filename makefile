all: compila executa

compila: main.o EliminacaoGauss.o
	gcc main.o EliminacaoGauss.o -o prog

main.o: main.c
	gcc -c main.c

EliminacaoGauss.o: EliminacaoGauss.c
	gcc -c EliminacaoGauss.c

executa:
	./prog.exe carbono14.txt

clean:
	del main.o EliminacaoGauss.o prog