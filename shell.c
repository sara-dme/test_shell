#include "main.h"

void launch_prog(char **args)
{
	pid_t pid;

	pid = fork();
	if (pid ==-1)
	{
		perror("child process could not be created");
		return;
	}

	if (pid == 0)
	{

		if (execve(args[0], args, NULL) == -1)
		{
			perror("./shell");
			kill(getpid(), SIGTERM);
		}
	}
	else
		waitpid(pid,NULL,0);
}
