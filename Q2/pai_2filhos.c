#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  // Criando Filho1
  pid_t pid = fork();
  // Verificação se o Filho1 foi criado
  if (pid == 0) {
    printf("Filho1 pid %d do Pai pid %d\n", getpid(), getppid());
  } 
  // Se o Filho1 não foi criado
  else if(pid == -1) {
    printf("Erro na criação do Filho1");
    return (1);
  }
  else{
    // Criação de Filho2
    if (fork() == 0) {
      printf("Filho2 pid %d do Pai pid %d\n", getpid(), getppid());
    }
    else {
    // Se o Filho2 não foi criado
    printf("Erro na criação do Filho2");
    return (2);
    }
  }
  return (0);
}
