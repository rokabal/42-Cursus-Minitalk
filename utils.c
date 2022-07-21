/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:22:09 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/20 18:43:10 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (sign < 0)
		result *= sign;
	return (result);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &("0123456789"[n % 10]), 1);
}

void	check_inputs(int pid, char *str)
{
	if (pid < 1)
	{
		write(1, "Error: Invalid server PID\n", 26);
		exit(EXIT_FAILURE);
	}
	if (!*str)
	{
		write(1, "Error: Empty message\n", 21);
		exit(EXIT_FAILURE);
	}
}
