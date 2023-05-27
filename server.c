/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachebla <yachebla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:07:33 by yachebla          #+#    #+#             */
/*   Updated: 2023/01/28 14:07:34 by yachebla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_process(int *sig, char *char_to_print)
{
    *char_to_print <<= 1;

    if (*sig == SIGUSR1)
        *char_to_print |= 1;
}
void signal_Controller(int sig, siginfo_t *info, void *empty)
{
	static int eight_bits = 0;
	static char char_to_print = 0;
	static pid_t c_pid = 0;

	(void)empty;
	if (c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		eight_bits = 0;
		char_to_print = 0;
	}
	signal_process(&sig, &char_to_print);
	eight_bits++;
	if (eight_bits == 8)
	{
		write(1, &char_to_print, 1);
		eight_bits = 0;
		char_to_print = 0;
	}
}

int main(int argc, char **argv)
{
	struct sigaction signal;

    signal.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = signal_Controller;
    (void)argv;
    if (argc == 1)
    {
        write(1, "I'm the server: ", 16);
        ft_putnbr(getpid());
		write(1, "\n", 1);
		sigaction(SIGUSR1, &signal, NULL);
		sigaction(SIGUSR2, &signal, NULL);
		while (1)
		{

		}
	}
	else
    {
		ft_putstr("ERROR\n");
    	return (1);
    }
}
