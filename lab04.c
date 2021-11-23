#include <stdio.h>
#include <stdlib.h>


void merge(int vetor[], int comeco, int meio, int fim,int vetor_indices[]) {
    int esquerda = comeco, direita = meio+1, aux = 0, tam = fim-comeco+1;

    int vetAux[tam];   // vetor auxiliar de tarefas
    int vetAuxi[tam];  // vetor auxiliar de indices 
   
    while(esquerda <= meio && direita <= fim){
        if(vetor[esquerda] <= vetor[direita]) {
            vetAux[aux] = vetor[esquerda];
            vetAuxi[aux] = vetor_indices[esquerda];
            esquerda++; } 
        else {
            vetAux[aux] = vetor[direita];
            vetAuxi[aux] = vetor_indices[direita];
            direita++;}
        aux++;}

    while(esquerda <= meio){  
        vetAux[aux] = vetor[esquerda];
        vetAuxi[aux] = vetor_indices[esquerda];
        aux++;
        esquerda++;}

    while(direita <= fim) {   
        vetAux[aux] = vetor[direita];
        vetAuxi[aux] = vetor_indices[direita];
        aux++;
        direita++;}

    for(aux = comeco; aux <= fim; aux++){    //Move os elementos de volta para o vetor original
        vetor[aux] = vetAux[aux-comeco];     // Vetor tarefas
        vetor_indices[aux] = vetAuxi[aux-comeco];}  // Vetor indices
        }

void mergeSort(int vetor[], int comeco, int fim,int vetor_indices[]){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio,vetor_indices);
        mergeSort(vetor, meio+1, fim,vetor_indices);
        merge(vetor, comeco, meio, fim,vetor_indices);
    }
}

void printvetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho - 1; i++) 
        printf("%d ", vetor[i]);
    printf("%d", vetor[tamanho-1]);
    printf("\n");}


int main()
{
    int tarefas = 0;
    scanf("%d",&tarefas);

    int *vetor_tarefas;
    int *vetor_indices;

    vetor_indices = (int*)malloc(tarefas * sizeof(int));
    vetor_tarefas = (int*)malloc(tarefas * sizeof(int));

    int tempo_processamento_atual[tarefas];
    int tempo_processamento_total = 0;

    for(int i = 0; i <= tarefas; i++){  // armazena o tempo de cada tarefa
        scanf("%d",&vetor_tarefas[i]);
        vetor_indices[i] = i+1;          //inicializa com os indices
        }


    mergeSort(vetor_tarefas, 0, tarefas -1 ,vetor_indices);  //ordena o vetor de tarefas
   

    tempo_processamento_atual[0] = vetor_tarefas[0];  // inicializa o tempo de processamento 

    for(int i = 1 ;i < tarefas;i++){
        tempo_processamento_atual[i] = tempo_processamento_atual[i-1] + vetor_tarefas[i];}

    for(int i = 0; i< tarefas; i++){
        tempo_processamento_total = tempo_processamento_total + tempo_processamento_atual[i];

    }
    printf("%d\n",tempo_processamento_total);
    printvetor(vetor_indices,tarefas);

    return 0;
} 

//gcc -std=c99 -pedantic -Wall -o lab04 lab04.c