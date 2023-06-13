/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/12 22:15:54 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <signal.h>

pid_t		g_clientpid;

static void	free_quit(char *tofree, int len)
{
	if (tofree)
		free(tofree);
	printf("\033[1;31mFailed memory allocation at '%i'.\033[0m\n", len);
	exit(1);
}

static int	sort_mem(int type, char *copy, char *str, int len)
{
	if (type == 1)
	{
		if (str == NULL)
		{
			printf("\033[1;31mFailed initial memory allocation.\033[0m\n");
			exit(1);
		}
	}
	if (type == 2)
	{
		if (copy == NULL)
			free_quit(str, len);
		ft_strncpy(copy, str, len + 1);
		free(str);
	}
	if (type == 3)
	{
		if (str == NULL)
			free_quit(copy, len);
		ft_strncpy(str, copy, len + 1);
		free(copy);
	}
	return (len);
}

static void	sort_string(int binary[8])
{
	static char	*str;
	static int	len;
	char		*copy;

	if (!len)
	{
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
	{
		len = print_string(str, len);
		kill(g_clientpid, SIGUSR1);
		return ;
	}
	len++;
}

static void	signalhandler(int signal, siginfo_t *info, void *context)
{
	int			j;
	static int	i;
	static int	binary[8];

	if (!i)
		i = 8;
	if (signal == SIGUSR1)
		binary[--i] = 0;
	else if (signal == SIGUSR2)
		binary[--i] = 1;
	if (!i)
		sort_string(binary);
	g_clientpid = info->si_pid;
	kill(g_clientpid, SIGUSR2);
	if (context)
		j = 0;
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	struct sigaction	sa;

	if (argc != 1 || argv[1])
	{
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
		exit(0);
	}
	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	sa.sa_sigaction = signalhandler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
