#include "microshell.h"

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

char *ft_strdup(char *str)
{
	char *copy = malloc(ft_strlen(str) + 1);
	if (!copy)
		return NULL;
	copy[ft_strlen(str)] = 0;
	for (int i = 0; str[i]; i++)
		copy[i] = str[i];
	return copy;
}

int pipeline_cmd_nbr(char **argv)
{
	int i = 0;

	while (argv[i] && !strcmp(argv[i], "|") && !strcmp(argv[i], ";"))
		i++;
	return i;
}

int copy_params(char **params, char **argv)
{
	int i = 0;
	while (argv[i] && !strcmp(argv[i], ";") && !strcmp(argv[i], "|"))
	{
		params[i] = ft_strdup(argv[i]);
		i++;
	}
	return i;
}

t_cmd *create_list(char **argv)
{
	int i = 0;
	int j = 0;
	t_cmd *cmds = malloc(sizeof(t_cmd));
	t_cmd *head = cmds;

	while (argv[i] && !strcmp(argv[i], ";"))
	{
		cmds->index = j++;
		cmds->params = malloc((pipeline_cmd_nbr(argv) + 1) * sizeof(char *));
		if (!cmds->params)
			return NULL;
		cmds->cmd = cmds->params[0];
		cmds->params[pipeline_cmd_nbr(argv)] = 0;
		argv += copy_params(cmds->params, argv);
		i = 0;
		if (argv[i] && !strcmp(argv[i], ";"))
		{
			cmds->next = malloc(sizeof(t_cmd));
			cmds = cmds->next;
		}
		else
			cmds->next = NULL;
		argv += 1;

	}
	return head;
}

void exec(char **argv, char **envp)
{
	t_cmd *pipe_line = create_list(argv);
	while (pipe_line)
	{
		printf("%s\n", pipe_line->cmd);
		pipe_line = pipe_line->next;
	}
}

int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		return 0;
	argv += 1;
	int i = 0;

	while (argv[i])
	{
		if (!strcmp(argv[i], ";"))
		{
			exec(argv, envp);
			argv += i + 1;
			i = 0;
		}
		i++;
	}


}
