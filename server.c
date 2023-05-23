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

void signal_process(int *sig, char *p_char)
{
    if (*sig == SIGUSR1)
        *p_char = (*p_char << 1) | 1;
    else if (*sig == SIGUSR2)
        *p_char = *p_char << 1;
}

void signal_handler(int sig, siginfo_t *info, void *data)
{
    static int eight_bits = 0;
    static char p_char = 0;
    static pid_t c_pid = 0;

    (void)data;
    
    if (c_pid != info->si_pid)
    {
        c_pid = info->si_pid;
        eight_bits = 0;
        p_char = 0;
    }

    signal_process(&sig, &p_char);

    eight_bits++;

    if (eight_bits == 8)
    {
        write(1, &p_char, 1);
        eight_bits = 0;
        p_char = 0;
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = signal_handler;
    (void)argv;
    if (argc == 1)
    {
        write(1, "I'm the server: ", 16);
        ft_putnbr(getpid());
		write(1, "\n", 1);
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		while (1)
			pause();
	}
	else
		ft_putstr("ERROR\n");
}
