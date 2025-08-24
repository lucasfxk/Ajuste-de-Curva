all: compila

compila: main.o EliminacaoGauss.o
	gcc main.o EliminacaoGauss.o -o prog -lm

main.o: main.c
	gcc -c main.c

EliminacaoGauss.o: EliminacaoGauss.c
	gcc -c EliminacaoGauss.c

clean:
	del main.o EliminacaoGauss.o prog

cleanrm:
	rm main.o EliminacaoGauss.o prog
