#include "monty.c"
/**
 * parse_monty_file - Parse an opened monty file.
 *
 * @file: file to parse
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int parse_monty_file(FILE *file)
{
monty_t *m;
stack_t *tmp;
stack_t *curr;
char *line;
size_t len;
unsigned int line_number;

m = malloc(sizeof(monty_t));
if (!m)
{
return (EXIT_FAILURE);
}
m->saveptr = NULL;
m->stack = NULL;

line = NULL;
len = 0;
line_number = 0;
while (getline(&line, &len, file) != -1)
{
execute_command(m, line, line_number);
++line_number;
}

/* Free memory */
tmp = m->stack;
while (tmp)
{
curr = tmp;
tmp = tmp->next;
free(curr);
}
/*free(m->stack);*/
free(m);
free(line);
return (EXIT_SUCCESS);
}
