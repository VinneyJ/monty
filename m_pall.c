#include "monty.h"

/**
 * m_pall - Print all command.
 *
 * @m: monty structure
 * @line_number: current line number in the monty file
 * Return: void
 */
void m_pall(monty_t *m, unsigned int line_number)
{
(void) line_number;
stack_t *stack;

stack = m->stack;
while (stack)
{
printf("%i\n", stack->n);
stack = stack->next;
}
}
