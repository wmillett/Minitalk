/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:10 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/09 16:41:22 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"
#include <signal.h>
#include <stdio.h>

static void	sendsignal(pid_t serv_pid, int signal_number)
{
	int	i;

	if (!signal_number)
	{
		i = 8;
		while (i--)
		{
			kill(serv_pid, SIGUSR1);
			usleep(100);
		}
	}
	else
		kill(serv_pid, signal_number);
	usleep(100);
}

static void	atob(pid_t serv_pid, char *str)
{
	int		i;
	char	c;
	int		bit;

	i = 0;
	while (str[i])
	{
		c = str[i];
		bit = 7;
		while (bit >= 0)
		{
			if ((c >> bit) & 1)
				sendsignal(serv_pid, SIGUSR2);
			else
				sendsignal(serv_pid, SIGUSR1);
			bit--;
		}
		i++;
	}
	sendsignal(serv_pid, 0);
}

static void	handle_exit(int type)
{
	write(2, "\033[1;31m", 7);
	if (type == 1)
		printf("Wrong number of arguments.\n");
	write(2, "\033[0m", 4);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	serv_pid;

	if (argc != 3)
		handle_exit(1);
	serv_pid = ft_atoi(argv[1]);
	atob(serv_pid, argv[2]);
}
