/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:50:02 by bgoncalv          #+#    #+#             */
/*   Updated: 2022/01/03 03:35:47 by bgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <signal.h>

static t_com	g_com;

void	ft_reset_com(t_com *g_com)
{
	g_com->isreading = 1;
	g_com->index = 0;
	g_com->bi = 0;
	ft_bzero(g_com->buffer, BSIZE);
}

void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	(void) context;
	g_com.buffer[g_com.index] <<= 1;
	if (signum == SIGUSR1)
		g_com.buffer[g_com.index] |= 1;
	if (++g_com.bi == 8)
	{
		g_com.bi = 0;
		if (!g_com.buffer[g_com.index])
		{
			g_com.isreading = 0;
			kill(info->si_pid, SIGUSR1);
		}
		else
			++g_com.index;
	}
	if (g_com.index == BSIZE)
	{
		write(1, g_com.buffer, BSIZE);
		ft_reset_com(&g_com);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	ft_reset_com(&g_com);
	ft_printf("Server PID : %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
	{
		pause();
		if (g_com.isreading == 0)
		{
			write(1, g_com.buffer, g_com.index);
			ft_putchar('\n');
			ft_reset_com(&g_com);
		}
	}
	return (0);
}
