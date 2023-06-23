/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:10 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/23 17:29:29 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

t_handle_pid		g_serv;

static inline void	atob(pid_t serv_pid, char *str, int time)
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

static void	itob(pid_t serv_pid, int len, int time)
{
	int	i;
	int	c;
	int	bit;

	i = 0;
	{
		c = len;
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
}

static void	handle_exit(int type)
{
	if (type == 1)
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
	if (type == 2)
		printf("\033[1;31mWrong server PID or server error.\033[0m\n");
	if (type == 3)
		printf("\033[1;31mServer error: could not receive the message.\033[0m\n");
	exit(0);
}

static void	sighandler(int signum)
{
	static int	i;
	static int	count = 0;

	if (!g_serv.initm)
		i = -1;
	if (signum == SIGUSR1)
	{
		printf("\033[1;34mMessage received sucessfully!\033[0m\n");
		exit(0);
	}
	if (signum == SIGUSR2)
	{
		i++;
		if (!i)
			print_prog(count, g_serv.len);
		if (i >= (g_serv.len / 10) && g_serv.len > 100)
		{
			count += 10;
			print_prog(count, g_serv.len);
			i = 0;
		}
		g_serv.initm = 1;
	}
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	int					time;
	struct sigaction	sa;

	sa.sa_handler = sighandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	g_serv.initm = 0;
	if (argc != 3)
		handle_exit(1);
	serv_pid = ft_atoi(argv[1]);
	g_serv.len = ft_strlen(argv[2]);
	time = sort_time(g_serv.len);
	itob(serv_pid, g_serv.len, time);
	atob(serv_pid, argv[2], time);
	if (g_serv.initm)
		usleep(g_serv.len * time);
	else
		handle_exit(2);
	handle_exit(3);
}
