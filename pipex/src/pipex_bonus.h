/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:05:01 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/26 17:06:32 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>

void	bonus_child_process(int *pipe_end, char **argv, char **env);
void	bonus_parent_process(int *pipe, char **argv, char **env);
void	bonus_handle_error(const char *msg);
void	bonus_free_array(char **arr);
void	bonus_execute_cmd(char *cmd, char **env);
void	handle_here_doc(char *delimiter, char **argv, char **env);

#endif
