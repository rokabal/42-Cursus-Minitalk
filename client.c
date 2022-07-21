/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:34:12 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/21 16:18:17 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Correct usage ./client serverPID msg\n", 37);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	check_inputs(pid, argv[2]);
	send_msg_binary(pid, argv[2]);
}
