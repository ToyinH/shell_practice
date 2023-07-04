#include "simple_shell.h"
#define MAX 10
/**
 *
 */

void prompt_user2(char **av, char **envt)
{
	char *str = NULL, *token;
	size_t n = 0;
	int i, k, status;
	char *argv[MAX];
	pid_t child_pid;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("cisfun$ ");
		ssize_t char_num = getline(&str, &n, stdin);
		if (char_num == -1)
			free(str), exit(EXIT_FAILURE);
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		k = 0;
		argv[k] = strtok(str, " ");
		while (argv[k])
		{
			argv[k] = strtok(NULL, " ");
			k++;
		}
		child_pid = fork();
		if (child_pid == -1)
			free(str), exit(EXIT_FAILURE);
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, envt) == -1);
				printf("%s, no such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
