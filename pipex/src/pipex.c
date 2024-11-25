/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:07:07 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/25 15:57:00 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(char *cmd, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = extract_path(cmd_args[0], env);
	if (!cmd_path)
	{
		handle_error("Command not found");
	}
	if (!cmd_args)
	{
		handle_error("Command split failed");
	}
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		free_array(cmd_args);
		free(cmd_path);
		handle_error("Execve failed");
	}
	free_array(cmd_args);
	free(cmd_path);
}

static void	handle_child_process(int *pipe_end, char **argv, char **env)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		handle_error("Error opening infile");
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_end[1], STDOUT_FILENO);
	close(pipe_end[0]);
	execute_cmd(argv[2], env);
}

static void	handle_parent_process(int *pipe_end, char **argv, char **env)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		handle_error("Error opening outfile");
	dup2(pipe_end[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_end[1]);
	execute_cmd(argv[3], env);
}

static void	create_process(int *pipe_end, char **argv, char **env, int is_child)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		handle_error("Fork failed");
	if (child_pid == 0)
	{
		if (is_child)
			handle_child_process(pipe_end, argv, env);
		else
			handle_parent_process(pipe_end, argv, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pipe_end[2];

	if (argc != 5)
		handle_error("Invalid number of arguments");
	if (pipe(pipe_end) == -1)
		handle_error("Pipe creation failed");
	create_process(pipe_end, argv, env, 1);
	create_process(pipe_end, argv, env, 0);
	close(pipe_end[0]);
	close(pipe_end[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
