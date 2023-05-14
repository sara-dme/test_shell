#include "main.h"
#include  <errno.h>
void exec_cmd(char **toks);

void exec_cmd(char **toks)
{
char *cmd = toks[0];
	/*execute the command */
	/*printf("cmd : %s", cmd);*/
               if (execve(cmd, &toks[0], NULL) == -1)
                  {
                         perror("./shell: ");
		  }
}
int main()
{
	char *line;/* var to stock the input */
	char *line_copy; /*copy of line */
	char *delim = "\n";
 	size_t sz = 0;
	ssize_t num_char;
	int num_tok = 0;
	char *tok;
	char **toks;
	int i = 0;

while (1) {
                printf("($)");
                num_char = getline(&line, &sz, stdin);
		if (num_char == -1)
                             {
                        /*exiting the shell if failed or EOF */
                        printf("exit ....\n");
                        exit(-1);
                }
		line_copy = malloc(sizeof(char) * num_char);
		if (line_copy == NULL)
		{
			perror("cmd null");
			return (-1);
		}
		/* make a copy of line */
		strcpy(line_copy, line);
		/* split line */
		tok = strtok(line, delim);

	while (tok != NULL)
	{
		num_tok++;
		tok = strtok(NULL, delim);
	}	
	num_tok++;
	toks = malloc(sizeof(char *) * num_tok);
	
	/*store tok in toks array */
	tok = strtok(line_copy, delim);
	for(i = 0; tok != NULL; i++)
	{
		toks[i] = malloc(sizeof(char) * strlen(tok));
		strcpy(toks[i], tok);
		tok = strtok(NULL, delim);
	}
	toks[i] = NULL;
	exec_cmd(toks);
	

	}

	return (0);
}
