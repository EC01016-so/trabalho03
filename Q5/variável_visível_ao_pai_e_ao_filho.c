#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

int variavel = 0;

int main() {
    
    // O Pai inicializa a variável com 1
    variavel = 1; 
    printf("%d\n", variavel);
    // Criação do Filho
    pid_t pid = fork();
    // Verifica se o filho foi criado
    if(pid == 0) {
        printf("Filho pid %d do Pai pid %d\n", getpid(), getppid());
        // O Filho altera o valor da variável para 5
        variavel = 5;
        printf("%d\n", variavel);
        exit(variavel);
    }
    // Caso o Filho não seja criado
    else if (pid == -1) {
        printf("Erro na criação do Filho");
        return (1);
    }
    // O Pai imprime a variavel novamente
    else {
        waitpid(pid, NULL, 8);
        printf("Após alteração por Filho %d\n", variavel);
    }
    return (0);
}
