#ifndef MAIN_H
#define MAIN_H
void execute_command(char *input);
void handle_eof(void);
void handle_error(char *message);
int main(void);
void display_prompt(void);
#endif
