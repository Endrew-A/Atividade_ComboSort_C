#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void bubble(int *vetor,int qtd);

int comparacoes=0, trocas=0;
int main(){

    FILE *arquivo = fopen("numerosrandom.csv","r");
    if(arquivo== NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int numeros[100000];
    char linha [100];
    int qtd=0, repeticoes=1;
    while(fgets(linha,sizeof(linha),arquivo)!= NULL){
        //linha[strcspn(linha,"\n")]=0;
        //num = strtok(linha,",");
        numeros[qtd] = atoi(linha);

        qtd++;
    }
    clock_t inicio = clock();

    for(int i=0;i<repeticoes;i++){ //é repetido várias vezes e depois dividido pela qtd de repetições
        bubble(numeros,qtd);       //para obter um valor mais aproximado da realidade (que foi gasto)
    }
    clock_t fim = clock();
    float tempogasto = ((float)(fim-inicio))/CLOCKS_PER_SEC/repeticoes;

    //for(int i=0;i<qtd;i++){
      //  printf("%d\n",numeros[i]);
    //}
    printf("Quantidade de numeros: %d / Tempo gasto: %.10f / Comparacoes: %d / Trocas: %d",qtd,tempogasto, (int)(comparacoes/repeticoes),(int)(trocas/repeticoes));
    fclose(arquivo);
    return 0;
}

void bubble(int *vetor,int qtd){
    for(int i=0;i<qtd;i++){
        for(int j=0;j<qtd;j++){
            comparacoes++;
            if(vetor[i]< vetor[j]){
            int temp = vetor[j];
            vetor[j] = vetor[i];
            vetor[i]= temp;
            trocas++;
            }
        }
    }

}
