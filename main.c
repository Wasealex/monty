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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *full_str;
	int line_number = 0;

	if (ag != 2)
	{
		puts("USAGE: monty file");
		return (EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	while ((read = getline(&line, &len, file)) != -1)
	{
		full_str =  strstrip(line);
		printf("%s", full_str);
		line_number++;
		free(full_str);
	}
	printf("total line number is %d\n", line_number);
	fclose(file);
	free(line);
	return (0);
}
