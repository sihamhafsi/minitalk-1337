/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shafsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:04:07 by shafsi            #+#    #+#             */
/*   Updated: 2022/06/11 19:04:50 by shafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	c = 0xFF;
	static int	client_pid = 0;

	(void) context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0xFF;
		bit = 0;
	}
	if (signum == SIGUSR1)
		c |= 128 >> bit;
	else if (signum == SIGUSR2)
		c ^= 128 >> bit;
	if (++bit == 8)
	{
		ft_putchar(c);
		bit = 0;
		c = 0xFF;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	if (ac != 1 || av[1] != NULL)
	{
		ft_putstr("error\n");
	}
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	ft_putstr("Server started successfully and now waiting for client\n");
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
}
