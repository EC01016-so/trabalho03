#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid == 0) {
    printf("Filho1 pid %d do Pai pid %d\n", getpid(), getppid());
  } 
  else if(pid == -1) {
    printf("Error em criação filho");
  }
  else{
    if (fork() == 0) {
      printf("Filho2 pid %d do Pai pid %d\n", getpid(), getppid());
    }
  }
  return (0);
}