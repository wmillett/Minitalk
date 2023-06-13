/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:10 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/12 22:17:07 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"
#include <signal.h>
#include <stdio.h>

int			g_initm = 0;

static void	sendsignal(pid_t serv_pid, int signal_number, int time)
{
	int	i;

	if (!signal_number)
	{
		i = 8;
		while (i--)
		{
			kill(serv_pid, SIGUSR1);
			usleep(time);
		}
	}
	else
		kill(serv_pid, signal_number);
	usleep(time);
}

static void	atob(pid_t serv_pid, char *str, int time)
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
				sendsignal(serv_pid, SIGUSR2, time);
			else
				sendsignal(serv_pid, SIGUSR1, time);
			bit--;
		}
		i++;
	}
	sendsignal(serv_pid, 0, time);
}

static void	handle_exit(int type)
{
	if (type == 1)
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
	if (type == 2)
	{
		printf("\033[1;31mWrong server PID or server error.\033[0m\n");
	}
	if (type == 3)
		printf("\033[1;31mServer error: could not receive the message.\033[0m\n");
	exit(0);
}

static void	sighandler(int signum)
{
	static int i;
	
	if (!g_initm)
		i = 0;
	if (signum == SIGUSR1)
	{
		printf("\033[1;34mMessage received sucessfully!\033[0m\n");
		exit(0);
	}
	if (signum == SIGUSR2)
	{
		if (!i)
			printf("\033[1;35mServer connection established.\033[0m\n");
		i = 1;
		g_initm = 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	int					len;
	int					time;
	struct sigaction	sa;

	sa.sa_handler = sighandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 3)
		handle_exit(1);
	serv_pid = ft_atoi(argv[1]);
	len = ft_strlen(argv[2]);
	time = sort_time(len);
	atob(serv_pid, argv[2], time);
	if (g_initm)
		usleep(len * time);
	else
		handle_exit(2);
	sleep(1);
	handle_exit(3);
}
