/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:13:16 by yachebla          #+#    #+#             */
/*   Updated: 2023/05/30 18:13:32 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static	void	ft_send_bit_signals(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(450);
	}
}

void	msg(int sig)
{
	if (sig == SIGUSR2)
	{
		write (1, "Has been Received successfully\n", 30);
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	size_t	i;
	size_t	len;

	i = 0;
	if (argc != 3)
	{
		ft_putstr("Error: invalid number of arguments\n");
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	if (pid_server <= 0)
	{
		ft_putstr("Error: invalid process ID\n");
		return (1);
	}
	signal (SIGUSR2, msg);
	len = ft_strlen(argv[2]);
	while (len >= i)
	{
		ft_send_bit_signals(pid_server, argv[2][i]);
		i++;
	}
	return (0);
}
