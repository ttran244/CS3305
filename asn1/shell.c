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

int main(int argc, char** argv)
{
    char input;
    char name = NULL;
    while (name == NULL) 
    {
      printf("Enter your name:\n");
      scanf("%s", &name);
    }
    while (1)
    {
      printf("%s>", &name);
      scanf("%s", &input);
    }
  return 0;
}
