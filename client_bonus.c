/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:12 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/21 19:17:06 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_msg_binary(int pid, char *str)
{
	int	i;
	int	bitshift;

	i = 0;
	while (str[i])
	{
		bitshift = 7;
		while (bitshift >= 0)
		{
			if (str[i] & (1 << bitshift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift--;
			usleep(50);
		}
		i++;
	}
}

void	confirm(int signo, siginfo_t *info, void *context)
{
	if (signo == SIGUSR1)
	{
		write(1, "Message received!\n", 18);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = confirm;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		write(1, "Correct usage ./client_bonus serverPID msg\n", 43);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	check_inputs(pid, argv[2]);
	send_msg_binary(pid, argv[2]);
	while (1)
	{
		pause();
	}
}
