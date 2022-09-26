#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	return (i);
}

void	error_printer(char *error, char *argument)
{
	write(2, error, ft_strlen(error));
	if (argument)
	{
		write(2, " ", 1);
		write(2, argument, ft_strlen(argument));
	}
	write(2, "\n", 1);
}

void	ft_cd(char **args)
{
	if (!args[1] || args[2])
		error_printer("error: cd: bad arguments", NULL);
	else if (chdir(args[1]) == -1)
		error_printer("error: cd: cannot change directory to", args[1]);
}

void	exec(char **args, int is_piped, int old_stdin, char **env)
{
	int	pid = 0;
	int	fd[2];
	
	if (strcmp(args[0], "cd") == 0)
	{
		ft_cd(args);
		return ;
	}
	if (is_piped && pipe(fd) == -1)
	{
		close(old_stdin);
		error_printer("error: fatal", NULL);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(old_stdin);
		error_printer("error: fatal", NULL);
		exit(1);
	}
	if (pid == 0)
	{
		if (is_piped)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
		execve(args[0], args, env);
		error_printer("error: could not execute", args[0]);
		close(old_stdin);
		exit(1);
	}
	else
	{
		if (is_piped)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
		}
		else
			dup2(old_stdin, 1);
		waitpid(pid, 0, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	old_stdin = dup(0);
	int	is_piped = 0;
	int	i = 1;
	int	j = 1;

	(void)argc;
	while (argv[i])
	{
		if (strcmp(argv[i], "|") == 0 || strcmp(argv[i], ";") == 0)
		{
			if (strcmp(argv[i], "|") == 0)
				is_piped = 1;
			argv[i] = NULL;
			exec(argv + j, is_piped, old_stdin, env);
			is_piped = 0;
			j = i + 1;
		}
		else if (argv[i + 1] == NULL)
			exec(argv + j, is_piped, old_stdin, env);
		i++;
	}
	close(old_stdin);
	return (0);
}
