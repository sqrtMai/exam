#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_cmd
{
	char *cmd;
	char **params;
	int index;
	struct s_cmd *next;
}	t_cmd;

#endif
