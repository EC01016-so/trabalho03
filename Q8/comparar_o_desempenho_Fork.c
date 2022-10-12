#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <wait.h>

// Criando variaveis do tipo clock_t
clock_t iniciar, parar;
unsigned long t,z;
double soma=0.0, media=0.0;

// Número de execuções da tarefa
int m = 20; 
// Arquivo que armazenará o resultado de tempo de execução e a média do tempo
FILE *fp;

// Função que contará o tempo de execução da tarefa
void *trabalho ()
{
    double k;
    iniciar = clock();
    for(t=0; t<100000000; t++){};
    parar = clock();
    soma += (double)(parar - iniciar) / CLOCKS_PER_SEC;
    k = (double)(parar - iniciar) / CLOCKS_PER_SEC;
    
    fprintf(fp,"\n O laço Fork precisou de %f segundos", k);
    
    printf("\n O laço Fork precisou de %f segundos", k);
    return(0);
}
// Função para calcular a média do tempo
void *clu_media(){
    media = soma / m;
    fprintf(fp, "\n A media do laço para Fork eh %f segundos", media);
    
    printf("\n A media do laço para Fork eh %f segundos\n", media);
    
    return (0);
}

int main(void)
{
    fp = fopen("arq_Fork.txt","w+");
    for (z=0; z<m; z++)
    {
        if(fork() == 0 )
        {
            trabalho();
            if(z== m-1)
            { 
                wait(0);    // Aguarda a saída do processo filho
                clu_media();
            }
            exit(0);
        }
        wait(0); // Aguarda 
    }
    fclose(fp);
    return (0);
}
