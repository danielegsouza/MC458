#include <stdio.h>
#include <stdlib.h>

// Funções que dado dois números do vetor de entrada retorna o maior ou o menor
double valor_max(double x, double y){

    if(x < y){
        return y;
    }

   return x;}

double valor_min(double x, double y){
    
    if(x <y){
        return x;
    }

return y;
}



int main(){

int i = 0;
int numero =0;
int tamanho = 0;
double sequencia_max = 0;
double sequencia_min = 0;
double max_produto = 0;
double min_produto = 0;
double max_atual = 0;
double seq_max_anterior = 0 ;



scanf("%i",&tamanho);

double sequencia[tamanho];

while(numero <tamanho){
    scanf("%lf",&sequencia[numero]);
    numero++;
}

// Compara cada valor da sequencia com o produto maximo da subsequencia anterior 
while(i < tamanho){

    seq_max_anterior = sequencia_max;

    max_produto = valor_max(sequencia_max*sequencia[i],sequencia_min*sequencia[i]);
    min_produto = valor_min(sequencia[i]*seq_max_anterior,sequencia_min*sequencia[i]);

    sequencia_max = valor_max(sequencia[i],max_produto);

    sequencia_min = valor_min(sequencia[i],min_produto);

    max_atual = valor_max(max_atual,sequencia_max);

    i++;
}


if(max_atual < 1){
    max_atual = 1;}


printf("%lf\n",max_atual);
    

return 0;
}

