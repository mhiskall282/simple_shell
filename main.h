#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/**
 * struct op - struct for built-in function operation
 * @str: character to check
 * @fp: function to point to
 */
typedef struct op
{
	char *str;
	int (*fp)(char **av, int *exit_status);
} built_in;


char **token();
int executor(char **av, char *argv[], int count, int *exit_status);
char *pathfinder(char **av);
int interpret(char **av, char *argv[], int count, int *exit_status);
int sh_exit(char **av, int *exit_status);
int sh_chdir(char **av, int *exit_status);

/** print error */
int _puterror(char c);
void _puts_error(char *str);
void _perror(char **av, char *argv[], int count);

/** string manipulation */
char *_itoa(int x);
void reverse_array(char *a, int n);

/** prompt */
void _prompt(void);

/** print function */
int _putchar(char c);
void _puts(char *str);

int printenv(char **av, int *exit_status);
int _unsetenv(char **av, int *exit_status);
int _setenv(char **av, int *exit_status);

int _isalpha(int c);

#endif
