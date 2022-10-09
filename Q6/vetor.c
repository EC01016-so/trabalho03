#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

//Variáveis globais
int vetor[100];    					//Vetor original
int ord[100];      					//Vetor ordenado
int aux[50], aux2[50]; 					//Vetores auxiliares
int inicio = 0, fim = 99, meio1 = 40;

//Funções para realizar o merge sort
void mergesort(int inicio, int fim);      		//Ordenação
void merge(int inicio, int meio, int fim); 		//Lista
void mergesort1(int inicio, int meio1);      		//Ordenação
void merge1(int inicio, int meio, int meio1);		//Auxiliar
void *sort(void *aux); 
void *sort1(void *vetor); 				//Threads

int main(){
    int n = 100, i;
    pthread_t t1, t2, t3; 				//Gerenciadores de threads

    printf("**********Merge Sort*********\n");
    printf("Insira 100 valores:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &vetor[i]); 				//Escreve os valores em vetor

    for(i = 0; i < 50; i++)
        aux[i] = vetor[i]; 					//Transfere a primeira metade ao vetor aux

    //Cria a thread executando a mergesort1
    pthread_create(&t1, NULL, sort, (void *)aux);
    pthread_join(t1, NULL); 				//Pausa o thread após sua execução

    for(i = 0; i < 50; i++)
        aux[i] = vetor[i+5]; 				//Transfere a segunda metade ao vetor aux

    //Cria a thread executando a mergesort1
    pthread_create(&t2, NULL, sort, (void *)aux);
    pthread_join(t2, NULL); 				//Pausa o thread após sua execução

    printf("\nVetor ordenado: \n");

    //Cria a thread executando a mergesort
    pthread_create(&t3, NULL, sort1,(void*)vetor);
    pthread_join(t3, NULL); 				//Pausa o thread após sua execução

    //Exibe o vetor ordenado
    for(i = 0; i < 100; i++)
        printf("%d\t",ord[i]);
    printf("\n");
}

//Função para organizar o vetor
void merge(int inicio, int meio, int fim){
	int l, r, i;
   	for(l = inicio, r = meio + 1, i = inicio; l <= meio && r <= fim; i++){
        	if (vetor[l] <= vetor[r]) {
        		ord[i] = vetor[l++];
        	}
        	else
        		ord[i] = vetor[r++];
    	}
    	while(l <= meio) {
    	 	ord[i++] = vetor[l++];
	}
    	while(r <= fim) {
    		ord[i++] = vetor[r++];
	}
    	for(i = inicio; i <= fim; i++) {
    		vetor[i] = ord[i];
	}
}

void mergesort(int inicio, int fim){
	int meio, elements = (intptr_t) vetor;        
	if(inicio < fim) {
	        meio = (inicio + fim) / 2;
	        mergesort(inicio, meio);
	        mergesort(meio+1, fim);
	        merge(inicio, meio, fim);
	} 
	else
		return;
}


//Função para organizar metade do vetor
void mergesort1(int inicio, int meio1){
	int meio, elements = (intptr_t)aux; 
	if(inicio < meio1) {
        	meio = (inicio + meio1) / 2;
        	mergesort1(inicio, meio);
        	mergesort1(meio+1, meio1);
        	merge1(inicio, meio, meio1);
        }
    else
    	return;  
}

void merge1(int inicio, int meio, int meio1){
	int l, r, i;
    	for(l = inicio, r = meio + 1, i = inicio; l <= meio && r <= meio1; i++){
        	if(aux[l] <= aux[r]) {
        		aux2[i] = aux[l++];
        	}
        	else
        		aux2[i] = aux[r++];
    	}
    	while (l <= meio) {
    		aux2[i++] = aux[l++];
	}
    	while(r <= meio1) {
    		aux2[i++] = aux[r++];
	}
	for(i = inicio; i <= meio1; i++) {
		aux[i] = aux2[i];
	}
}

void *sort(void *aux){
    mergesort1(inicio,meio1); //Função para executar a thread que ordena o vetor
}

void *sort1(void *vetor){
    mergesort(inicio,fim); //Função para executar a thread que ordena o vetor
}

