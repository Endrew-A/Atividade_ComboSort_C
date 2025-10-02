#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <time.h>

void combo(int *vetor,int qtd);

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
    combo(numeros,qtd);
    clock_t fim = clock();
    float tempogasto = ((float)(fim-inicio))/CLOCKS_PER_SEC;

    for(int i=0;i<qtd;i++){
        printf("%d\n",numeros[i]);
    }
    printf("Tempo gasto: %.10f",tempogasto);
    return 0;
}

void combo(int *vetor,int qtd){
    int gap = qtd;
    bool troca=true;
        while(gap>1 || troca){
            gap = (int)(gap / 1.3); //1.3 é o fator de redução do gap
            if(gap<1){gap=1;}
            troca=0;

            for(int i=0;i+gap<qtd;i++){
                if(vetor[i]< vetor[i+gap]){
                int temp = vetor[i+gap];
                vetor[i+gap] = vetor[i];
                vetor[i]= temp;
                troca=1;
                }
        }
    }

}
