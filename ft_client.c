/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:50:07 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/01/03 19:15:28 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <signal.h>
#include <stdio.h>
#define FREQ 100

void	check_handler(int signum)
{
	(void) signum;
	write(1, "Message has been received.\n", 27);
	exit(EXIT_SUCCESS);
}

void	ft_sendchar(int pid, char c)
{
	int	i;

	i = 8;
	while (i)
	{
		if (c & 1 << --i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(FREQ);
	}
}

void	ft_sendstr(int pid, char *s)
{
	while (*s)
		ft_sendchar(pid, *s++);
	ft_sendchar(pid, 0);
}

int	main(int argc, char **argv)
{
	int		serverpid;

	if (argc != 3 && argc != 4)
	{
		ft_putendl("Pleaser, enter the server's PID and a string");
		return (EXIT_SUCCESS);
	}
	serverpid = ft_atoi(argv[1]);
	signal(SIGUSR1, check_handler);
	ft_sendstr(serverpid, argv[2]);
	return (0);
}
