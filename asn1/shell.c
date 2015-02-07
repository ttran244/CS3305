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
#include "shellfuncts.c"

#define MAXLINE 1000

int main(int argc, char** argv)
{
    char line[MAXLINE];
    char name[MAXLINE];

    while (name[0] == '\0') 
    {
      printf("Enter your name:\n");
      fgets(name, MAXLINE, stdin);
    }

    while (1)
    {
      printf("%s>", name[0]);
      
      if (!fgets(line, MAXLINE, stdin))
      {
        return 0;
      }

      int input = 0;
      int first = 1;
      char* com = line;
      char* next = strchr(com, '|');

      while (next != NULL)
      {
        *next = '\0';
        input = run(com, input, first, 0);
        com = next + 1;
        next = strchr(com, '|');
        first = 0;
      }

      input = run(com, input, first, 1);
    }
    return 0;
}
