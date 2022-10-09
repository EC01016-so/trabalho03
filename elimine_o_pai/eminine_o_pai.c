#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid_do_pai;

    pid_do_pai = getpid();

    // Creiando novo processo Pai do Avô
    if (fork() == 0) {
        wait(0);  // Aguarda a saída do processo filho
        printf("Em Processo do Pai: %d, o Filho do Avô : %d\n",getpid(), getppid());
        
        if (fork() == 0) { // Creiando novo processo Filho do Pai
            printf("Em Processo do Filho: %d, o Filho do Pai : %d\n",getpid(), getppid());

            pid_do_pai = getppid();
            int elimina_o_pai = kill(pid_do_pai, 9); // Eliminando processo pai com sig 9 que é para matar o Pai

            if (elimina_o_pai == -1) {
                printf("error na eliminação do Pai");
            }
            printf("Apos elimina o Pai: %d agore o Pai do Filho: %d é %d\n",pid_do_pai, getpid(), getppid());
        }

    } else {
        wait(0); // Aguarda saída do processo pai
        printf("Processo Avô: %d\n o Pai do Avô: %d", getpid(),getppid());
    }
    
    return (0);
}
