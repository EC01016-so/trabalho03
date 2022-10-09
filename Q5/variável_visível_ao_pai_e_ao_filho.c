#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

int variavel;

int main() {
    pthread_t thread;

    variavel = 1;
    printf("%d\n", variavel);
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error em criação filho");
    } 

    if(pid == 0) {
        printf("Filho pid %d do Pai pid %d\n", getpid(), getppid());
        variavel += 5;
        printf("%d\n", variavel);
        exit(variavel);
    }
    else{
        waitpid(pid, NULL, 8);
        printf("Após alteração por Filho %d\n", variavel);
    }
       
    return (0);
}