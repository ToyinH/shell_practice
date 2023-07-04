#include "simple_shell.h"
/**
 *
 */

void prompt_user(char **av, char **envt)
{
	char *str;
	int i, status;
	char *argv[] = {NULL, NULL};
	pid_t child_pid;

	while (1)
	{
		if (isatty(fileno(stdin)))
			printf("cisfun$ ");

		str = handl_getline();
		argv[0] = str;
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
