#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int main() {

  pid_t pid_do_pai, pid_do_filho, pid_do_avo;

  pid_do_pai = getpid();

  printf("Processo pai ---->> PID do pai : %d\n", pid_do_pai);

  // Creiando novo processo do pai
  if (fork() == 0) {
    pid_do_filho = getpid();
    printf("Em Processo do filho ----->> PID do filho : %d\n", pid_do_filho);
    printf("e PID do pai : %d\n", pid_do_pai);

  // Creiando novo processo do pai
    if (fork() == 0) {
      pid_do_avo = pid_do_pai;
      pid_do_pai = pid_do_filho;
      pid_do_filho = getpid();

      printf("Em Processo do filho do processo PID: %d  ----->> PID do filho : "
             "%d\n",
             pid_do_pai, pid_do_filho);
      printf("e PID do pai : %d\n", pid_do_pai);
      printf("e PID do avô : %d\n", pid_do_avo);
      system("ps -f\n");

      // Eliminando processo pai
      int elimina_o_pai = kill(pid_do_pai, 0);
      if (elimina_o_pai == -1) {
        printf("error na eliminação do pai");
      }
    }
  } else {
    printf("Ainda em Processo pai PID: %d\n", pid_do_pai);
  }
  system("ps -f");
  return (0);
}
