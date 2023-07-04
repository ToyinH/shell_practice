#include "simple_shell.h"

/**
 *
 */
int main(int ac, char **av, char **envt)
{
	if (ac == 1)
	{
		prompt_user(av, envt);
	}
	return (0);
}
