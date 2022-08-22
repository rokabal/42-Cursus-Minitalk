/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:14 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/21 19:18:40 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<signal.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	check_inputs(int pid, char *str);

#endif
