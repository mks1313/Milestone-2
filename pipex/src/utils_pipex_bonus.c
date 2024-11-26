/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:05:34 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/26 17:08:46 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	bonus_handle_error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	bonus_free_array(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	bonus_child_process(int *pipe_end, char **argv, char **env)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		bonus_handle_error("Error opening infile");
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_end[1], STDOUT_FILENO);
	close(pipe_end[0]);
	bonus_execute_cmd(argv[2], env);
}

void	bonus_parent_process(int *pipe_end, char **argv, char **env)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		bonus_handle_error("Error opening outfile");
	dup2(pipe_end[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(pipe_end[1]);
	bonus_execute_cmd(argv[3], env);
}

void	handle_here_doc(char *delimiter, char **argv, char **env)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		bonus_handle_error("Pipe creation failed");
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	bonus_execute_cmd(argv[2], env);
}
