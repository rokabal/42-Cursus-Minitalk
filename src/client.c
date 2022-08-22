/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:12 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/24 15:44:30 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_received;

void	bit_one(int pid)
{
	if (kill(pid, SIGUSR1) == -1)
	{
		write(1, "Error sending signal\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	bit_zero(int pid)
{
	if (kill(pid, SIGUSR2) == -1)
	{
		write(1, "Error sending signal\n", 21);
		exit(EXIT_FAILURE);
	}
}

void	send_msg_binary(int pid, char *str)
{
	int	shift;

	while (1)
	{
		shift = 8;
		while (--shift >= 0)
		{
			if (*str & (1 << shift))
				bit_one(pid);
			else
				bit_zero(pid);
			while (!g_received)
				pause();
			g_received = 0;
		}
		if (!*str)
			break ;
		str++;
	}
}

void	confirm(int signo)
{
	if (signo == SIGUSR1)
		g_received = 1;
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Usage: ./client_bonus [serverPID] [msg]\n", 40);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, confirm);
	pid = ft_atoi(argv[1]);
	check_inputs(pid, argv[2]);
	send_msg_binary(pid, argv[2]);
}
