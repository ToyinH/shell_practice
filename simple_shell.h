#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt_user(char **av, char **envt);
int main(int ac, char **av, char **envt);

#endif
