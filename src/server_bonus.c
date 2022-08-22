/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:15 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/23 17:58:53 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	g_client_pid;

void	acknowledge(int client_pid, int signo)
{
	if (kill(client_pid, signo) == -1)
	{
		write(1, "\n", 1);
		g_client_pid = 0;
	}
}

void	decode_msg(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				n;

	if (!g_client_pid || info->si_pid == g_client_pid)
	{
		g_client_pid = info->si_pid;
		if (signo == SIGUSR1)
			c |= 1;
		if (++n == 8 && (1 || context))
		{
			if (!c)
				write(1, "\n", 1);
			else
				write(1, &c, 1);
			if (!c)
				g_client_pid = 0;
			n = 0;
			c = 0;
		}
		c <<= 1;
		usleep(100);
		acknowledge(info->si_pid, SIGUSR1);
	}
	else
		acknowledge(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = decode_msg;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
