/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:10 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/09 21:18:28 by wmillett         ###   ########.fr       */
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
			usleep(50);
		}
	}
	else
		kill(serv_pid, signal_number);
	usleep(50);
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
	if (type == 1)
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
	exit(0);
}

static void sighandler(int signum)
{
    if (signum == SIGUSR1)
        printf("\033[34mMessage received !\033[0m\n");
}

int	main(int argc, char **argv)
{
	pid_t	serv_pid;
	int 	time;
	
	struct sigaction sa;
	
	sa.sa_handler = sighandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
	
	if (argc != 3)
		handle_exit(1);
	serv_pid = ft_atoi(argv[1]);
	time = ft_strlen(argv[2]) * 200;
	atob(serv_pid, argv[2]);
	usleep(time);
}
