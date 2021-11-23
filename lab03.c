#include <stdio.h>
#include <stdlib.h>

int main()
{

	int n = 0;
	int i, j = 0;
	int k, l = 0;
	int entradas[5];
	int max = 0;
	int linhas = 0;

	
	scanf("%d", &n);  // tamanho do tabuleiro
	int *ordem = (int*)malloc(n*sizeof(int));   //vetor ordem dos indices
	int **tabuleiro = (int **)malloc(n * sizeof(int *));  //tabuleiro nxn

	for (i = 0; i < n; i++){												   
		tabuleiro[i] = (int *)malloc(n * sizeof(int)); 
		for (j = 0; j < n; j++){ 
			tabuleiro[i][j] = -1000000;     //inicializa com valor minimo de p
		}
	}

	int **indice = (int **)malloc(n * sizeof(int *)); //tabuleiro com indices

	for (i = 0; i < n; i++){												
		indice[i] = (int *)malloc(n * sizeof(int)); 
		for (j = 0; j < n; j++){ 
			indice[i][j] = 0;
		}	
	}


	//inicializa primeira linha do tabuleiro com zeros e do indice com os valores dos indices
	for (int j = 0; j < n; j++){
		tabuleiro[0][j] = 0;
		indice[0][j] = j;
	}

	linhas = ((n-2)*3*(n-1))+(4*(n-1));  // numero de entradas

	//preenche tabuleiro com valores de ganho

	for (k = 0; k < linhas; k++){
		for (l = 0; l < 5; l++){
			scanf("%d", &entradas[l]);
		}
		if (tabuleiro[entradas[2]][entradas[3]] == tabuleiro[entradas[0]][entradas[1]] + entradas[4]){
			if (indice[entradas[2]][entradas[3]] > entradas[1]){
				indice[entradas[2]][entradas[3]] = entradas[1];
				
			}
		}
		else if (tabuleiro[entradas[2]][entradas[3]] < tabuleiro[entradas[0]][entradas[1]] + entradas[4]){
			indice[entradas[2]][entradas[3]] = entradas[1];
			tabuleiro[entradas[2]][entradas[3]] = tabuleiro[entradas[0]][entradas[1]] + entradas[4];
		}
	}

max = 0;
for (j = 1; j < n; j++){
	if(tabuleiro[n - 1][max] < tabuleiro[n - 1][j]){
		max = j;
	}
}

printf("%d\n", tabuleiro[n - 1][max]);   //valor maximo coletado

for (i = n - 1; i >= 0; i--){
	ordem[i] = max;
	max = indice[i][max];
}

for (i = 0; i < n - 1; i++){
	printf("%d ", ordem[i]);}

printf("%d\n", ordem[n - 1]);
free(tabuleiro);
free(indice);
free(ordem);

return 0;
}

//gcc -std=c99 -pedantic -Wall -o lab03 lab03.c