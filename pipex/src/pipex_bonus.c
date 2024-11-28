/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:04:52 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/28 17:38:51 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	bonus_execute_cmd(char *cmd, char **env)
{
	char	**array_cmd;
	char	*path_env;

	array_cmd = ft_split(cmd, ' ');
	path_env = bonus_extract_path(array_cmd[0], env);
	if (!path_env)
	{
		bonus_free_array(array_cmd);
		bonus_handle_error("Error: comando no encontrado o ruta inválida.");
	}
	if (execve(path_env, array_cmd, env) == -1)
	{
		bonus_free_array(array_cmd);
		free(path_env);
		bonus_handle_error("Error: fallo al ejecutar el comando.");
	}
	bonus_free_array(array_cmd);
	free(path_env);
}

static void	write_in_pipe(char **av, int *p_end)
{
	char	*line;

	close(p_end[0]);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, av[2], ft_strlen(av[2])) == 0)
		{
			free(line);
			exit(0);
		}
		ft_putstr_fd(line, p_end[1]);
		free(line);
	}
}

static void	handle_heredoc(char **av)
{
	int		p_end[2];
	pid_t	np;

	if (pipe(p_end) == -1)
		bonus_handle_error("Error: fallo al crear el pipe.");
	np = fork();
	if (np == -1)
		bonus_handle_error("Error: fallo al hacer fork.");
	if (!np)
		write_in_pipe(av, p_end);
	else
	{
		close(p_end[1]);
		dup2(p_end[0], STDIN_FILENO);
		waitpid(np, NULL, 0);
	}
}

static void	exe_pipeline(char *cmd, char **env)
{
	int		p_end[2];
	pid_t	np;

	if (pipe(p_end) == -1)
		bonus_handle_error("Error: fallo al crear el pipe.");
	np = fork();
	if (np == -1)
		bonus_handle_error("Error: fallo al hacer fork.");
	if (!np)
	{
		close(p_end[0]);
		dup2(p_end[1], STDOUT_FILENO);
		bonus_execute_cmd(cmd, env);
	}
	else
	{
		close(p_end[1]);
		dup2(p_end[0], STDIN_FILENO);
		waitpid(np, NULL, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fdin;
	int	fdout;

	if (ac < 5)
		bonus_handle_error("Error: número incorrecto de argumentos.");
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			bonus_handle_error("Error: número incorrecto de argumentos.");
		fdout = bonus_open_file(av[ac - 1], 2);
		handle_heredoc(av);
		i = 3;
	}
	else
	{
		fdin = bonus_open_file(av[1], 0);
		fdout = bonus_open_file(av[ac - 1], 1);
		dup2(fdin, STDIN_FILENO);
		i = 2;
	}
	while (i < ac - 2)
		exe_pipeline(av[i++], env);
	dup2(fdout, STDOUT_FILENO);
	bonus_execute_cmd(av[ac - 2], env);
}
