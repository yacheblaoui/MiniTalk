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
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	i = 0;
	if (ac == 3)
	{
        pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
		write(1, "ERROR\n", 6);
		return(1);
        }
        while (ft_strlen(av[2]) >= i)
        ft_shift(pid, av[2][i++]);
	}
	else
		write(1, "ERROR\n", 6);
}
		