#include "main.h"

void cmds(char *args[], char **envp)
{
	char pwd[256];
	int j = 0;

          size_t length;
        const char newline = '\n';

	if (_strcmp(args[0], "exit") == 0)
                {
                        exit(0);
                }
	else if (_strcmp(args[0], "ls") == 0)
                {
                        *args = "/bin/ls";
                }
	else if (_strcmp(args[0], "env") == 0)
                {
                        for (j = 0; envp[j] != NULL; j++)
                        {
                                length = _strlen(envp[j]);
                                write(STDOUT_FILENO, envp[j], length);
                                write(STDOUT_FILENO, &newline, 1);
                        }
                }
	else if (strcmp(args[0],"pwd") == 0)
	{
		if (args[j] != NULL)
		{
			getcwd(pwd, sizeof(pwd));
			write(STDIN_FILENO, pwd, 1024);
		}
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			if (chdir(args[1]) == -1)
					perror(args[1]);
		}
	}

}
