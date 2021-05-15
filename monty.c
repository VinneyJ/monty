#include "monty.h"
/**
 * main - Monty interpreter.
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int main(int argc, char **argv)
{
FILE *file;

if (argc > 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

file = fopen(argv[1], "r");
if (!file)
{
printf("Error: Can't open file\n");
exit(EXIT_FAILURE);
}

if (parse_monty_file(file) == EXIT_FAILURE)
{
exit(EXIT_FAILURE);
}

fclose(file);
exit(EXIT_SUCCESS);
}
