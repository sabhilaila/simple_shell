#ifndef MAIN_H
#define MAIN_H
#define MAX_INPUT_SIZE 1024
void execute_command(char *input);
void handle_eof(void);
void handle_error(char *message);
int main(void);
void display_prompt(void);
#endif
