/*
 * shellfuncts.c
 *
 * Computer Science 3305
 * Assignment 1
 *
 * Author: Tommy Tran (ttran244@uwo.ca)
 * 
 * Functions for shell.c to run programs, create pipes, support I/O redirection,
 * exit command, and history command.
 */

#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shellfuncts.h"

#define MAX 500
#define READ 0
#define WRITE 1

pid_t pid; // holds the pid of the process
char* args[MAX]; // holds the arguements. 

/*
 * Helper function that finds the blank space in the command that is entered
 * by the user
 */
char* whitespace(char* string)
{
  while (isspace(*string))
  {
    ++string;
  }

  return string;
}

/*
 * 
 */
void split(char* com)
{
  com = whitespace(com);
  char* next = strchr(com,' ');
  int i = 0;

  while (next != NULL)
  {
    next[0] = '\0';
    args[i] = com;
    ++i;
    com = whitespace(next + 1);
    next = strchr(com, ' ');
  }

  if (com[0] != '\0')
  {
    args[i] = com;
    next = strchr(com, '\n');
    next[0] = '\0';
    ++i;
  }

  args[i] = NULL;
}

int command(int input, int first, int last)
{
  int fd[2];
  pipe(fd);
  pid = fork();

  if (pid == 0)
  {
    if (first == 1 && last == 0 && input == 0)
    {
      dup2(fd[WRITE], STDOUT_FILENO);
    }
    else if (first == 0 && last == 0 && input != 0)
    {
      dup2(input, STDIN_FILENO);
      dup2(fd[WRITE], STDOUT_FILENO);
    }
    else
    {
      dup2(input, STDIN_FILENO);
    }

    execvp(args[0], args);
  }

  if (input != 0)
  {
    close(input);
  }

  close(fd[WRITE]);

  if (last == 1)
  {
    close(fd[READ]);
  }

  return fd[READ];
}

int run(char* com, int input, int first, int last)
{
  int n = 0;
  split(com);
  if (args[0] != NULL)
  {
    if (strcmp(args[0], "exit") == 0)
    {
      exit(0);
    }
    else if (strcmp(args[0], "history") == 0)
    {
      // Prints list of commands
    }      
    n = n + 1;
    return command(input, first, last);
  }
  return 0;
}





















