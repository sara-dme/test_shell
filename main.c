#include "main.h"
#include  <errno.h>

void exec_cmd(char **args)
{
char *cmd = NULL;
	if (args)
	{
		cmd =  args[0];
		/*execute the command */
	      if (execve(cmd, args, NULL) == -1)
                  {
                         perror("./shell: ");
		  }
}
}

int main(int argc, char **argv)
{
	char *line, *line_copy;
	char *delim = "\n";
 	size_t sz = 0;
	ssize_t num_char;
	int num_tok = 0;
	char *tok;
	int i = 0;

	(void) argc;

while (1) 
{
                write(STDIN_FILENO,"#cisfun$ ", 9);
                num_char = getline(&line, &sz, stdin);
		if (num_char == -1)
                {
			free(line);
			perror("EXIT");
                        /*exiting the shell if failed or EOF */
                        exit(EXIT_SUCCESS);
                }
		line_copy = malloc(sizeof(char) * num_char);
		if (line_copy == NULL)
		{
			free(line);
			free(line_copy);
			perror("cmd null");
			exit (-1);
		}

		/* a changer */
		_strcpy(line_copy, line);
		/* split line */
		tok = strtok(line, delim);

	while (tok != NULL)
	{
		num_tok++;
		tok = strtok(NULL, delim);
	}	
	num_tok++;
	argv = malloc(sizeof(char *) * num_tok);
	
	/*store tok in toks array */
	tok = strtok(line_copy, delim);
	for(i = 0; tok != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(tok));
		_strcpy(argv[i], tok);
		tok = strtok(NULL, delim);
	}
	argv[i] = NULL;

	launch_prog(argv);
}
	free(line_copy);
	free(line);
	return (0);

}
