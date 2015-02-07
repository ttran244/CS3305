/*
 * shell.c
 *
 * Computer Science 3305
 * Assignment 1
 *
 * Author: Tommy Tran (ttran244@uwo.ca)
 *
 * A basic shell that accepts input from the user on the command line 
 * and executes programs based on the input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX 500
#define NUMPIPE 2
#define READ 0
#define WRITE 1

static char* args[MAX];
pid_t pid;
int command_pipe[NUMPIPE];

int main(int argc, char** argv)
{
    char input[MAX];
    char name = NULL;
    char* path = "/bin/";

    while (name == NULL) 
    {
      printf("Enter your name:\n");
      scanf("%s", &name);
    }
    while (1)
    {
      printf("%s>", &name);
      fgets(input, MAX, stdin);
      int pid = fork();
      if (pid != 0)
      {
        wait(NULL);
      }
      else
      {
        strcat(path, input);
        int x = execv(path, input);
      }


    }
  return 0;
}
