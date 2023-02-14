/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:30:34 by yachebla          #+#    #+#             */
/*   Updated: 2023/02/14 14:06:20 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int n);

#endif