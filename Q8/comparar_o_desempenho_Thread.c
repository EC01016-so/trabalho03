#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <wait.h>


clock_t iniciar, parar;
unsigned long t,z;
double soma=0.0, media=0.0;
int m =20; // Número de execuções da tarefa
FILE *fp;

void *trabalho ()
{   double k;
    iniciar = clock();
    for(t=0; t<100000000; t++){};
    parar = clock();
    soma += (double)(parar - iniciar) / CLOCKS_PER_SEC;
    k = (double)(parar - iniciar) / CLOCKS_PER_SEC;
    
    fprintf(fp,"\n O laço do Thread precisou de %f segundos", k);
    
    printf("\n O laço do Thread precisou de %f segundos", k);
    pthread_exit(0);
}

void *clu_media(){
    media = soma / m;
    fprintf(fp, "\n A media do laço para thread eh %f segundos", media);
    
    printf("\n A media do laço para thread eh %f segundos\n", media);
    
 return 0;
}

int main(void)
{
    pthread_t thread;
    fp = fopen("arq_Thread.txt","w+");
    for (z=0; z<m; z++)
    {
        pthread_create(&thread, NULL, trabalho, NULL);
        pthread_join(thread, NULL);
    }
    clu_media();
    fclose(fp);
    return (0);
}