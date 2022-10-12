#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
void *thread (void *c){ 
    // Threads
}
  
int main()
{
    int erro = 0, contador = 0, pid, pidmax = 0;
        pthread_t t;
    
    // Cria threads
    while (erro == 0){
        erro = pthread_create (&t, NULL, thread, NULL);
        contador++;
    }
    printf("Máximo de threads: %d\n", contador);
 
    // Cria processos      
    while (1) {
        pid = fork();
        pidmax = getpid();
        if(pid == 0){
            if(pidmax < getpid())
            pidmax = getpid();
            printf("Processos criados: %d\n", pidmax);  
            return 0;
        }
        if(pid == -1) {
            printf("Máximo de processos: %d\n", pidmax);
            exit(-1);
        }
    }
}
