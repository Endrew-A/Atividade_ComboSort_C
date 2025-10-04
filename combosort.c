#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <time.h>

void combo(int *vetor,int qtd);

int comparacoes=0, trocas=0;

int main(){
    FILE *arquivo = fopen("numerosrandom.csv","r");
    if(arquivo== NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int numeros[100000];
    char linha [100];
    int qtd=0, repeticoes=100;
    while(fgets(linha,sizeof(linha),arquivo)!= NULL){
        //linha[strcspn(linha,"\n")]=0;
        //num = strtok(linha,",");
        numeros[qtd] = atoi(linha);

        qtd++;
    }
    clock_t inicio = clock();
    for(int i=0;i<repeticoes;i++){
       combo(numeros,qtd);
    }
    clock_t fim = clock();
    float tempogasto = ((float)(fim-inicio))/CLOCKS_PER_SEC/repeticoes;

    //for(int i=0;i<qtd;i++){
    //    printf("%d\n",numeros[i]);
    //}
    printf("Quantidade de numeros: %d / Tempo gasto: %.10f / Comparacoes: %d / Trocas: %d",qtd,tempogasto, (int)(comparacoes/repeticoes),trocas);
    return 0;
}

void combo(int *vetor,int qtd){
    int gap = qtd;
    bool trocou=true;
        while(gap>1 || trocou){
            gap = (int)(gap / 1.3); //1.3 é o fator de redução do gap
            if(gap<1){gap=1;}
            trocou=0;

            for(int i=0;i+gap<qtd;i++){
                comparacoes++;
                if(vetor[i]< vetor[i+gap]){
                int temp = vetor[i+gap];
                vetor[i+gap] = vetor[i];
                vetor[i]= temp;
                trocas++;
                trocou=1;
                }
        }
    }

}
