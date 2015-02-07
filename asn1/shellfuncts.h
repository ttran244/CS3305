/*
 * shellfuncts.h
 *
 * Computer Science 3305
 * Assignment 1
 *
 * Author: Tommy Tran (ttran244@uwo.ca)
 *
 * Header file for shellfuncts.c, which stores the functions
 * for the shell to run.
 */

#ifndef SHELLFUNCTS_H
#define SHELLFUNCTS_H

char* whitespace(char* string);
void split(char* input);
int command(int input, int first, int last);






#endif
