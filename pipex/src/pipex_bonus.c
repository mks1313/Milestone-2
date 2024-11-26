/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:04:52 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/26 18:18:32 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*bonus_create_full_path(char *dir, char *cmd)
{
	char	*path;
	char	*full_path;

	path = ft_strjoin(dir, "/");
	full_path = ft_strjoin(path, cmd);
	free(path);
	return (full_path);
}

static char	*bonus_extract_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*full_path;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = bonus_create_full_path(paths[i], cmd);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			bonus_free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	bonus_free_array(paths);
	return (NULL);
}

void	bonus_execute_cmd(char *cmd, char **env)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	cmd_path = bonus_extract_path(cmd_args[0], env);
	if (!cmd_path)
	{
		bonus_handle_error("Command not found");
	}
	if (!cmd_args)
	{
		bonus_handle_error("Command split failed");
	}
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		bonus_free_array(cmd_args);
		free(cmd_path);
		bonus_handle_error("Execve failed");
	}
	bonus_free_array(cmd_args);
	free(cmd_path);
}

static void	create_process(int *pipe_end, char **argv, char **env, int is_child)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		bonus_handle_error("Fork failed");
	if (child_pid == 0)
	{
		if (is_child)
			bonus_child_process(pipe_end, argv, env);
		else
			bonus_parent_process(pipe_end, argv, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pipe_end[2];

	if (argc < 5)
		bonus_handle_error("Invalid number of arguments");
	if (argc == 6 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		handle_here_doc(argv[2], argv, env);
		return (0);
	}
	if (pipe(pipe_end) == -1)
		bonus_handle_error("Pipe creation failed");
	create_process(pipe_end, argv, env, 1);
	create_process(pipe_end, argv, env, 0);
	close(pipe_end[0]);
	close(pipe_end[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
