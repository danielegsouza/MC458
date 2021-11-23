#include <stdio.h>
#include <math.h>

void ordenacao_linear(int vetor[], int tamanho, int expoente){

    int indices[] = {0,0,0,0,0,0,0,0,0,0};   // vetor que guarda os indices 
    int saida[tamanho];                      // vetor ordenado

    // calculo da frequencia de indices
    for(int i = 0; i < tamanho; i++){
        indices[(vetor[i]/expoente)%10]++;}

    // somas parciais da frequencia dos indices
    for(int i = 1; i < 10; i++){
        indices[i] =  indices[i]+indices[i-1];}

    // ordenacao na saida
    for(int i = tamanho- 1; i >= 0; i--){
        saida[indices[(vetor[i]/expoente)%10]-1] = vetor[i];
        indices[(vetor[i]/expoente)%10]--;}

    // copia para o vetor inicial
    for(int i = 0; i < tamanho; i++){
        vetor[i] = saida[i];}
}

int main(){

    int tamanho = 0;
    int digitos = 0;
    scanf("%i",&tamanho);
    digitos = log10(pow(tamanho, 2)-1) + 1;   //calcula o numero de digitos do valor maximo de entrada

    int sequencia[tamanho];
    for (int i = 0; i < tamanho; i++){
        scanf("%i",&sequencia[i]);
    }

    //ordenacao do vetor
    int expoente = 1;
    for(int i=0; i<digitos; i++){
        ordenacao_linear(sequencia, tamanho, expoente);
        expoente *= 10;
    }

    // imprimindo a saida 
    for(int i = 0; i < tamanho; i++){
        if(i==tamanho-1){
            printf("%i\n",sequencia[i]);}

        else{
            printf("%i ",sequencia[i]);}
    }

return 0;
}