#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char *argv[])
{
  pid_t pid;

  if (-1 == write(1, "Hello World!\n", strlen("Hello World!\n")))
  {
    perror("Cannot greet the world");
    exit(-1);
  }

  pid = fork();

  if (pid == 0)
  {
    printf("This is the child, pid %d\n", getpid());
  }
  else
  {
    printf("This is the parent, pid %d\n", getpid());
  }

  return 0;
}
