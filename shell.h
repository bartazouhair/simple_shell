#ifndef SHELL_H
#define SHELL_H

/*---LIBRARIES---*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/*---Macros---*/
extern char **environ;
#define TOK_DELIM " \t\r\n\a\""


/*---PROTOTYPES---*/
/* main.c */
void mode_interactive(void);
void mode_no_interactive(void);

/* shell_interactive.c */
char *get_line(void);
char **line_split(char *line);
int handling_args(char **argv);

/* execute_args */
int process_handling(char **argv);

/* shell_no_interactive */
char *stream_reading(void);

/*---Builtin func---*/
int my_own_cd(char **argv);
int my_own_exit(char **argv);
int my_own_env(char **argv);
int my_own_help(char **argv);

#endif
