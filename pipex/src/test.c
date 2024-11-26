/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:18:05 by mmarinov          #+#    #+#             */
/*   Updated: 2024/11/26 16:26:50 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
/* Creamos un proceso hijo con fork() */
	pid = fork();
	if (pid > 0)
	{
		/* Estamos en el proceso padre */
		printf("Yo padre mi PID es %d y el PID de hijo es %d\n", getpid(), pid);
	}
	else if (pid == 0)
	{
		/* Estamos en el proceso hijo */
		printf("Soy el proceso hijo, mi PID es %d\n", getpid());
	}
	else
	{
		/* Error en la creación del proceso hijo */
		perror("Error al crear el proceso hijo");
	}
	return (0);
}
