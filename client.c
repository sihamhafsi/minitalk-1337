/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shafsi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:02:32 by shafsi            #+#    #+#             */
/*   Updated: 2022/06/11 19:03:18 by shafsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk.h"

void	send_signal(int PID, int n)
{
	if (n == 1)
	{
		if (kill(PID, SIGUSR1) == -1)
			exit(EXIT_FAILURE);
	}
	else
	{
		if (kill(PID, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
	}
}

void	send_bits(int PID, char *str)
{
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	while (1)
	{
		while (bit < 9)
		{
			if (str[i] & (128 >> bit))
				send_signal(PID, 1);
			else
				send_signal(PID, 0);
			bit++;
			usleep(300);
			if (bit == 8)
			{
				bit = 0;
				break ;
			}
		}
		if (!str[i])
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3 || av[2][0] == '\0')
	{
		ft_putstr("client: invalid arguments.\n");
		ft_putstr("correct format: [./client <PID> <STR_TO_SEND>].\n");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	send_bits(pid, av[2]);
}
