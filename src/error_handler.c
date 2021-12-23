#include "./../includes/pipex.h"

void    error_handler(char *str)
{
    ft_putendl_fd(STDERR_FILENO, str);
	exit (1);
}
