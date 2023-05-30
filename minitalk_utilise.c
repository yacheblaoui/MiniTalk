/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:52:49 by yachebla          #+#    #+#             */
/*   Updated: 2023/05/27 16:05:08 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
	{
		ft_putchar(n + '0');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr (n *(-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int	ft_atoi(char *s)
{
	int			i;
	int			j;
	long int	nb;

	i = 0;
	j = 1;
	nb = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i++] == '-')
			j = -1;
	}
	while (s[i] >= '0' && '9' >= s[i])
	{
		s[i] -= '0';
		nb = (nb * 10) + s[i++];
	}
	nb *= j;
	return (nb);
}
