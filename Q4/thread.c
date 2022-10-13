#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

char *abc[3];

// Função para printar na tela ABC
void *task_thread(void *tarefa){
    int i = 0;
    sleep(1);
    long Id_do_tarefa;
    Id_do_tarefa = (long)tarefa;
    printf("%s", abc[Id_do_tarefa]);
    i+=1;
    if(i == 2){
        printf("\n");
    }
    // Fazer a thread repetir a mesma ordem
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[3];
    long tarefa[3];
    abc[0] = "A"; // Mensagem 1
    abc[1] = "B"; // Mensagem 2
    abc[2] = "C\n"; // Mensagem 3

    for(int i = 0; i < 3; i++){
        tarefa[i] = i;
        // Criação de threads com pthread_create
        pthread_create(&threads[i], NULL, task_thread, (void *) tarefa[i]); 
        // Fazer a thread repetir a mesma ordem
        pthread_join(threads[i], NULL);
    }
    pthread_exit(NULL); // Fazer a thread repetir a mesma ordem
    return (0);
}