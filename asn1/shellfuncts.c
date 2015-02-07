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

#define MAX 500
#define READ 0
#define WRITE 1

pid_t pid;
char* args[MAX];

char* whitespace(char* string)
{
  while (isspace(*string))
  {
    ++string;
  }

  return string;
}

void split(char* input)
{
  input = whitespace(input);
  char* next = strchr(input,'');
  int i = 0;

  while (next != NULL)
  {
    next


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























