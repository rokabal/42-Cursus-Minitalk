/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:15 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/21 19:24:58 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	decode_msg(int signo, siginfo_t *info, void *context)
{
	static char	c;
	static int	n;

	if (signo == SIGUSR1)
		c |= 1;
	if (signo == SIGUSR1 || signo == SIGUSR2)
		n++;
	if (n == 8)
	{
		write(1, &c, 1);
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		n = 0;
		c = 0;
	}
	if (signo == SIGUSR1 || signo == SIGUSR2)
		c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = decode_msg;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "This is my pid: ", 16);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}
