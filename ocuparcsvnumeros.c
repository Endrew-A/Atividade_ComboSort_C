#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>


int main(){
    FILE *arquivo = fopen("numerosrandom.csv", "w");
    if(arquivo==NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    int random;
    int max=100000; //editar para gerar numero desejado
    srand(time(NULL));
        for(int i=0;i<max;i++){
            random = rand() % 10001;
            if(i == max-1){
                fprintf(arquivo,"%d",random);
            }else{
                fprintf(arquivo,"%d\n",random);
            }
        }
    fclose(arquivo);
    printf("Arquivo criado.");

    return 0;
}


