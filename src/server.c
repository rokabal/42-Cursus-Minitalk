/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:15 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/24 15:49:42 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode_msg(int signo, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				n;

	(void)context;
	if (signo == SIGUSR1)
		c |= 1;
	if (++n == 8)
	{
		if (!c)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		n = 0;
		c = 0;
	}
	c <<= 1;
	usleep(100);
	kill(info->si_pid, SIGUSR1);
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
