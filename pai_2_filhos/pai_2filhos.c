#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

  
  
int main()
{
    for(int i=0;i<2;i++) // loop será executado n vezes (n = 2)
    {
        int d = i+1;
        if(fork() == 0)
        {
            printf("Filho%d pid %d do Pai pid %d\n",d, getpid(),getppid());
            exit(0);
        }
    }
    for(int i=0;i<2;i++) //  loop será executado n vezes (n = 2)
    wait(NULL);
      
}