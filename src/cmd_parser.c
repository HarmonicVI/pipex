#include "./../includes/pipex.h"

char	**cmd_parser(const char *cmd)
{
	char	**args;

	if (cmd == NULL)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (args == NULL || *args == NULL)
		return (NULL);
	return (args);
}
