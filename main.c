#include "monty.h"
/**
 *main - entry point
 *@ag: no of arguments
 *@av: vector of argument
 *Return: 0 if success
 */
int main(int ag, char **av)
{
	FILE *file;
	char *line;
	size_t len = 0;
	ssize_t read;

	if (ag != 2)
	{
		puts("USAGE: monty file");
		return (EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	while ((read = getline(&line, &len, file)) != -1)
	{
		printf("%s", line);
	}
	fclose(file);
	return (0);
}
