#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void bubble(int *vetor,int qtd);
int main(){

    FILE *arquivo = fopen("numerosrandom.csv","r");
    if(arquivo== NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int numeros[1000];
    char linha [100];
    int qtd=0;
    while(fgets(linha,sizeof(linha),arquivo)!= NULL){
        //linha[strcspn(linha,"\n")]=0;
        //num = strtok(linha,",");
        numeros[qtd] = atoi(linha);

        qtd++;
    }
    clock_t inicio = clock();
    bubble(numeros,qtd);
    clock_t fim = clock();
    float tempogasto = ((float)(fim-inicio))/CLOCKS_PER_SEC;

    for(int i=0;i<qtd;i++){
        printf("%d\n",numeros[i]);
    }
    printf("Tempo gasto: %.10f",tempogasto);
    return 0;
}

void bubble(int *vetor,int qtd){
    for(int i=0;i<qtd;i++){
        for(int j=0;j<qtd;j++){
            if(vetor[i]< vetor[j]){
            int temp = vetor[j];
            vetor[j] = vetor[i];
            vetor[i]= temp;
            }
        }
    }

}
