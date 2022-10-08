#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int veriaveGrobal = 0;

int main() {
  int veriavelDoFuncao = 20;

  pid_t pid_do_pai, pid_do_filho, pid_do_avo;

  pid_do_pai = getpid();

  printf("Processo pai ---->> PID do pai : %d\n", pid_do_pai);

  if (fork() == 0) {
    pid_do_filho = getpid();
    printf("Em Processo do filho ----->> PID do filho : %d\n", pid_do_filho);
    printf("e PID do pai : %d\n", pid_do_pai);

    if (fork() == 0) {
      pid_do_avo = pid_do_pai;
      pid_do_pai = pid_do_filho;
      pid_do_filho = getpid();

      printf("Em Processo do filho do processo PID: %d  ----->> PID do filho : "
             "%d\n",
             pid_do_pai, pid_do_filho);
      printf("e PID do pai : %d\n", pid_do_pai);
      printf("e PID do avô : %d\n", pid_do_avo);
    }
  } else {
    printf("Processo pai");
  }
  system("ps -f");
  return (0);
}
