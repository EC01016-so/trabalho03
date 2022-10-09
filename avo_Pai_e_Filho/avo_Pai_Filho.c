#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    // Creiando novo processo Pai do Avô
    if (fork() == 0) {

        if (fork() == 0) { // Creiando novo processo Filho do Pai
            printf("Em Processo do Filho: %d, o Pai : %d\n",getpid(), getppid());
        }
        
        else {
          wait(0);  // Aguarda a saída do processo filho
          printf("Em Processo do Pai: %d, o Filho do Avô : %d\n",getpid(), getppid());
        }

    } else {
        wait(0); // Aguarda saída do processo pai
        printf("Processo Avô: %d e o Pai do Avô: %d \n", getpid(),getppid());
    }
    
    return (0);
}
