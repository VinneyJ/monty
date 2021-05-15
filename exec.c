#include "monty.h"

/**
 * execute_command - Checks if `line` is a valid command and executes it.
 *
 * @m: monty_t structure
 * @line: command to execute
 * @line_number: current line number of the monty file
 * Return: void
 */
void execute_command(monty_t *m, char *line, unsigned int line_number)
{
instruction_t *instr;
char *token;

instruction_t instructions[] = {
{"push", m_push},
{"pall", m_pall},
{NULL, NULL}
};

token = strtok_r(line, "\n ", &m->saveptr);
if (token)
{
for (instr = instructions; instr->opcode; ++instr)
{
if (strcmp(token, instr->opcode) == 0)
{
instr->f(m, line_number);
return;
}
}
printf("error: opcode `%s` not found.\n", token);
}
printf("error: invalid token\n");
}
