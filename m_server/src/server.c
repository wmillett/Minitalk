/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/22 01:51:42 by lightyagami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

t_sigpid	g_clientpid;

int	sort_string(int binary[8], int type)
{
	static char	*str;
	static int	len;

	if (type == ERROR)
		return (free_quit(str = NULL, len = 0, ERROR));
	if (!g_clientpid.len)
	{
		str = (char *)malloc((btoi(binary) + 1) * sizeof(char));
		len = sort_mem(str);
		g_clientpid.len = TRUE;
	}
	else
	{
		str[len] = btoa(binary);
		if (str[len] == '\0')
			return (len = print_string(str, len), kill(g_clientpid.pid,
					SIGUSR1));
		len++;
	}
	kill(g_clientpid.pid, SIGUSR2);
	return (0);
}

void	form_char(int signal)
{
	static int	i;
	static int	binary[8];

	if (signal == ERROR)
	{
		i = 8;
		while (i)
			binary[--i] = 0;
		return ;
	}
	if (!i)
		i = 8;
	binary[--i] = signal;
	if (!i && !g_clientpid.len)
		sort_string(binary, FALSE);
	else if (!i)
		sort_string(binary, TRUE);
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

void	set_toreset(void)
{
	g_clientpid.tick = FALSE;
	g_clientpid.active = FALSE;
	g_clientpid.len = FALSE;
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
	while (TRUE)
	{
		if (g_clientpid.active)
		{
			if (g_clientpid.tick++ > 20000)
			{
				reset_server();
				set_toreset();
			}
		}
		usleep(10);
	}
}
