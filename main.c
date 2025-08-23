#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./header/EliminacaoGauss.h"

#define QTD_AMOSTRA 48



int main(int argc, char const *argv[]){
    if (argc != 2){
            printf("ERRO: excesso ou falta de argumentos!");
            exit(1);
        }

    long long int dados[QTD_AMOSTRA][2];
    FILE *arquivo = fopen(argv[1], "r");
    for(int x=0;x<QTD_AMOSTRA;x++){
        fscanf(arquivo,"%lli %lli\n", &dados[x][0], &dados[x][1]);
    }

    for(int x=0;x<QTD_AMOSTRA;x++){
        printf("%lli\t%f\n",dados[x][0],pow((double)dados[x][0],2));
    }


    double resultado=0;
    //--------Matriz X--------
    double **matrizX = (double**) malloc(2 * sizeof(double*));
    for(int x=0;x<2;x++){
            matrizX[x] = (double*) malloc(2 * sizeof(double));
    }
    
    printf("\nResultado X:\n");
    for(int x=0;x<2;x++){
        for(int y=0;y<2;y++){
            resultado=0;
            for(int i=0;i<QTD_AMOSTRA;i++){
                resultado += pow((double)dados[i][0],x+y);
            }
            matrizX[x][y] = resultado;
            printf("%f ",matrizX[x][y]);
        }
        printf("\n");
    }
    //------------------------

    
    printf("\nResultado Y:\n");
    //--------Matriz Y--------
    double *matrizY = (double*) malloc(2 * sizeof(double));

    for(int x=0;x<2;x++){
        resultado = 0;
        for(int i=0;i<QTD_AMOSTRA;i++){
            resultado += log((double)dados[i][1]) * pow((double)dados[i][0],x);
        }
        matrizY[x] = resultado;
        printf("%f ",matrizY[x]);
    }

    //------------------------

    double* bias;
    bias = resolverEliminacaoGauss(matrizX,matrizY,2);

    printf("\nEuler: %f",exp(bias[0]));


    return 0;
}