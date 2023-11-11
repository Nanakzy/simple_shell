#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

int main(void);
void show_prompt(void);
void wait_for_child_process(pid_t pid);
void get_file_stats(const char *filename);
void read_user_input(char **line, size_t *len);
pid_t get_parent_pid(void);
pid_t get_current_pid(void);
pid_t create_child_process(void);
int execute_command(const char *command, char *args[]);
int parse_and_execute(char *input);
void handle_execution_error(void);
int check_command_in_path(const char *command);
void print_environment(void);
ssize_t custom_getline(char **line, size_t *len);
int tokenize_input(char *input, char *args[]);
int is_integer(const char *str);
void exit_builtin(char *args[]);



#endif
