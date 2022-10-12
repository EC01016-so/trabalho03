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

    // Criando novo processo Pai do Avô
    if (fork() == 0) {
        printf("No processo do Pai: %d , o Filho do Avô: %d\n",getpid(), getppid());
        
        // Criando novo processo Filho do Pai
        if (fork() == 0) {
            
            printf("No processo do Filho: %d , o Filho do Pai: %d\n",getpid(), getppid());
            pid_do_pai = getppid();
            
            // Eliminando processo pai com sinal 9, que é para matar o Pai
            int elimina_o_pai = kill(pid_do_pai, 9);
            
            // Verifica se o Pai foi eliminado
            if (elimina_o_pai == -1) {
                printf("Erro na eliminação do Pai");
            }
            printf("Após eliminar o Pai: %d , agora o Pai do Filho: %d é %d\n",pid_do_pai, getpid(), getppid());
        }

    } else {
        // Aguarda saída do processo Filho
        wait(0);
        printf("No processo Avô: %d , o Pai do Avô: %d\n", getpid(),getppid());
    }
    
    return (0);
}
