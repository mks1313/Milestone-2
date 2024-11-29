/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:05:34 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/29 12:09:13 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	bonus_handle_exit(void)
{
	ft_putstr_fd("Error: Incorrect numbers of arguments\n", 2);
	ft_putstr_fd("Pls Input: ./pipex infile cmd1 cmd2 ... outfile\n", 1);
	ft_putstr_fd("Or Input: ./pipex here_doc LIMITER  cmd cmd1 file\n", 1);
	exit(0);
}

void	bonus_handle_error(const char *msg)
{
	perror(msg);
	exit(-1);
}

int	bonus_open_file(char *file, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(file, O_RDONLY);
	if (flag == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (flag == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		bonus_handle_error("Error, mejorar");
	return (fd);
}

void	bonus_free_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

char	*bonus_extract_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**allpaths;
	char	*fullpath;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	allpaths = ft_split(env[i] + 5, ':');
	i = 0;
	while (allpaths[i])
	{
		path = ft_strjoin(allpaths[i], "/");
		fullpath = ft_strjoin(path, cmd);
		free(path);
		if (access(fullpath, F_OK | X_OK) == 0)
		{
			bonus_free_array(allpaths);
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	bonus_free_array(allpaths);
	return (NULL);
}
