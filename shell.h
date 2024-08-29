#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

/* Function Prototypes */

void sig_handler(int sig);
char *read_input(void);
char **tokenize_input(char *input);
int execute(char **args);
char *find_path(char *command);
void handle_exit(void);
void print_env(void);


#endif /* SHELL_H */
