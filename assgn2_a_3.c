#include<stdio.h>
#include<sys/types.h>

int main()
{
  pid_t cpid;
  
  cpid = fork();
  if(cpid == 0)
  {
    sleep(20);
    printf("\nThis is child process");
    printf("\nMy process id is %d ", getpid());
    printf("\nMy parent process is %d", getppid());
  }
  else
  {
    sleep(5);
    printf("\nMy process id is %d", getpid());
    printf("\nMy parent process id is %d\n", getppid());
  }
  
  return 0;
}

