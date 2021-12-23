#include "./../includes/pipex.h"

int	piper_heredoc(int in, int out, char *limiter, int pip)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		error_handler("Failed to create a fork.");
	else if (pid == 0)
	{
		close(in);
		ret = ft_heredoc(out, limiter, pip);
		if (ret == -1)
			error_handler("Failed to handle heredoc.");
		exit(SUCCESS);
	}
	else
	{
		close(out);
		dup2(in, STDIN_FILENO);
		wait(NULL);
	}
	return (in);
}

void    piper(int in, int out, char *cmd, char **envp)
{
	pid_t	pid;

	if (dup2(in, STDIN_FILENO) == -1)
		error_handler("Failed to connect fd in with STDIN");
	close(in);
	if (dup2(out, STDOUT_FILENO) == -1)
		error_handler("Failed to connect fd in with STDOUT");
	close(out);
	pid = fork();
	if (pid == -1)
		error_handler("Failed to create a fork.");
	else if (pid == 0)
		executer(cmd, envp);
}
