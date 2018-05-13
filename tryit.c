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

  if (argc < 2)
  {
    perror("Usage: tryit command");
    exit(-1);
  }

  pid = fork();

  if (pid == 0)
  {
    if (-1 == execv(argv[1], argv + 1))
    {
      perror("Error: ");
      exit(-1);
    }
  }
  else
  {
    wait(&status);
    if (status == 0)
    {
      printf("Process %d succeeded.\n", pid);
    }
    else
    {
      printf("Process %d exited with an error value.\n", pid);
    }
    exit(status);
  }

  return 0;
}
