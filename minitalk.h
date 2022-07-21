/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:29:14 by rkassouf          #+#    #+#             */
/*   Updated: 2022/07/20 18:35:01 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<unistd.h>
# include<stdlib.h>
# include<signal.h>

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	check_inputs(int pid, char *str);

#endif
