/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:07:18 by yachebla          #+#    #+#             */
/*   Updated: 2023/02/14 15:09:01 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	char_by_char(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(250);
	}
}

int	main(int ac, char **av)
{
	size_t	i;

	i = 0;
	if (ac == 3)
	{
		if (ft_atoi(av[1]) <= 0)
		{
			ft_putstr("ERROR\n");
			return (1);
		}
		while (ft_strlen(av[2]) >= i)
		{
			char_by_char(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("ERROR\n");
}
