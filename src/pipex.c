/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:46 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/15 15:28:28 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	if (argc != 5)  // Verifica si la cantidad de argumentos es correcta
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (1);
	}

	int fd1 = open(argv[1], O_RDONLY);  // Abre el primer archivo para lectura
	if (fd1 < 0)
	{
		ft_putstr_fd("Error opening file1\n", 2);
		return (1);
	}

	int fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);  // Abre el segundo archivo para escritura
	if (fd2 < 0)
	{
		ft_putstr_fd("Error opening file2\n", 2);
		close(fd1);
		return (1);
	}

	int pipefd[2];  // Pipe para la comunicación entre los dos procesos
	if (pipe(pipefd) == -1)  // Crea el pipe
	{
		ft_putstr_fd("Pipe failed\n", 2);
		close(fd1);
		close(fd2);
		return (1);
	}

	pid_t pid = fork();  // Crea un proceso hijo
	if (pid == -1)
	{
		ft_putstr_fd("Fork failed\n", 2);
		close(fd1);
		close(fd2);
		close(pipefd[0]);
		close(pipefd[1]);
		return (1);
	}

	if (pid == 0)  // Proceso hijo
	{
		// Redirige la entrada (stdin) al archivo fd1
		dup2(fd1, 0);
		close(fd1);

		// Redirige la salida (stdout) al pipe
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);

		// Ejecuta el primer comando
		char *cmd1[] = {argv[2], NULL};  // Comando 1
		if (execvp(cmd1[0], cmd1) == -1)
		{
			ft_putstr_fd("Command 1 execution failed\n", 2);
			return (1);
		}
	}
	else  // Proceso padre
	{
		// Redirige la entrada (stdin) al pipe
		dup2(pipefd[0], 0);
		close(pipefd[1]);

		// Redirige la salida (stdout) al archivo fd2
		dup2(fd2, 1);
		close(fd1);
		close(fd2);

		// Ejecuta el segundo comando
		char *cmd2[] = {argv[3], NULL};  // Comando 2
		if (execvp(cmd2[0], cmd2) == -1)
		{
			ft_putstr_fd("Command 2 execution failed\n", 2);
			return (1);
		}
	}

	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}
