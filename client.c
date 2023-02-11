/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:07:29 by yachebla          #+#    #+#             */
/*   Updated: 2023/01/28 14:07:30 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	ft_shift(int pid, char c)
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
		write(1, "ERROR\n", 6);
		return(1);
        }
        while (ft_strlen(av[2]) >= i)
		{
        	ft_shift(ft_atoi(av[1]), av[2][i]);
			i++;
		}
	}
	else
		write(1, "ERROR\n", 6);
}
		