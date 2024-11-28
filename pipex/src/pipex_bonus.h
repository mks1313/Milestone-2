/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:05:01 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/28 16:27:19 by mmarinov         ###   ########.fr       */
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

void	bonus_handle_error(const char *msg);
void	bonus_free_array(char **arr);
char	*bonus_extract_path(char *cmd, char **env);
int		bonus_open_file(char *file, int flag);
void	bonus_handle_exit(void);

#endif
