#include "simple_shell.h"

/**
 *
 */

char *handl_getline()
{
	char *string = NULL;
	size_t n = 0;
	int i;
	ssize_t char_num = getline(&string, &n, stdin);

	if (char_num == -1)
	{
		free(string);
	       	exit(EXIT_FAILURE);
	}
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			string[i] = 0;
		i++;
	}
	return (string);
}
