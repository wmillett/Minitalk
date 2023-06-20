/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 18:09:58 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <signal.h>

t_sigpid	g_clientpid;

int	print_string(char *str, int len)
{
	write(2, str, len);
	write(2, "\n", 1);
	free(str);
	g_clientpid.tick = FALSE;
	g_clientpid.active = FALSE;
	return (0);
}

int	sort_string(int binary[8], int check_reset)
{
	static char	*str;
	static int	len;
	char		*copy;

	if (check_reset == TRUE)
		return (free_quit(str = NULL, len = 0, ERROR));
	if (!len)
	{
		kill(g_clientpid.pid, SIGUSR2);
		str = (char *)malloc(sizeof(char) + 1);
		len = sort_mem(1, NULL, str, 0);
	}
	else
	{
		copy = (char *)malloc(sizeof(char) * (len + 1));
		sort_mem(2, copy, str, len);
		str = (char *)malloc(sizeof(char) * (len + 2));
		sort_mem(3, copy, str, len);
	}
	str[len] = btoa(binary);
	if (str[len] == '\0')
		return (len = print_string(str, len), kill(g_clientpid.pid, SIGUSR1));
	len++;
	return (0);
}


void form_char(int signal)
{
	static int	i;
	static int	binary[8];

	if (signal == ERROR)
	{
		i = 8;
		while(i)
			binary[--i] = 0;
		return ;
	}
	if (!i)
		i = 8;
	binary[--i] = signal;
	if (!i)
		sort_string(binary, FALSE);
}

void	signalhandler(int signal, siginfo_t *info, void *context)
{
	(void)*context;
	g_clientpid.tick = FALSE;
	g_clientpid.active = TRUE;
	g_clientpid.pid = info->si_pid;
	if (signal == SIGUSR1)
		form_char(0);
	else if (signal == SIGUSR2)
		form_char(1);
}

static void	check_args(int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
		exit(0);
	}
	g_clientpid.tick = FALSE;
	g_clientpid.active = FALSE;
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	struct sigaction	sa;

	check_args(argc, argv);
	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	sa.sa_sigaction = signalhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (g_clientpid.active)
		{
			if (g_clientpid.tick > 100000)
			{
				reset_server();
				g_clientpid.tick = FALSE;
				g_clientpid.active = FALSE;
			}
			g_clientpid.tick++;
		}
		usleep(10);
	}
}
