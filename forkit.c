#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
  pid_t pid;
  int status;

  if (-1 == write(1, "Hello World!\n", strlen("Hello World!\n")))
  {
    perror("Cannot greet the world");
    exit(-1);
  }

  pid = fork();

  if (pid == 0)
  {
    printf("This is the child, pid %d.\n", getpid());
    exit(0);
  }
  else
  {
    printf("This is the parent, pid %d.\n", getpid());
    wait(&status);
    printf("This is the parent, pid %d, signing off.\n", getpid());
  }

  return 0;
}
