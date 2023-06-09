/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/09 16:38:02 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <signal.h>

static void	free_quit(char *tofree, int len)
{
	if (tofree)
		free(tofree);
	write(2, "\033[1;31m", 7);
	printf("Failed memory allocation at '%i'.\n", len);
	write(2, "\033[0m", 4);
	exit(0);
}

static int	sort_mem(int type, char *copy, char *str, int len)
{
	if (type == 1)
	{
		if (str == NULL)
		{
			write(2, "\033[1;31m", 7);
			printf("Failed initial memory allocation.\n");
			write(2, "\033[0m", 4);
			exit(0);
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
		if (copy == NULL)
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
		print_string(str, len);
		free(str);
		len = 0;
		return ;
	}
	len++;
}

// static void sort_string(int binary[8])
// {
// 	static char* str;
// 	static int len;
// 	char* copy;

// 	if (!len)
// 	{
// 		str = (char*)malloc(sizeof(char) + 1);
// 		len = sort_mem(1, NULL, str);
// 	}
// 	else
// 	{
// 		copy = (char*)malloc(sizeof(char) * (len + 1));
// 		ft_strncpy(copy, str, len + 1);
// 		free(str);
// 		str = (char*)malloc(sizeof(char) * (len + 2));
// 		ft_strncpy(str, copy, len + 1);
// 		free(copy);
// 	}
// 	str[len] = btoa(binary);
// 	if (str[len] == '\0')
// 	{
// 		print_string(str, len);
// 		len = 0;
// 		return ;
// 	}
// 	len++;
// }

static void	signalhandler(int signal)
{
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
}

int	main(int argc, char **argv)
{
	pid_t	serv_pid;

	if (argc != 1 || argv[1])
	{
		write(2, "\033[1;31m", 7);
		printf("Wrong number of arguments.\n");
		write(2, "\033[0m", 4);
		exit(0);
	}
	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	signal(SIGUSR1, signalhandler);
	signal(SIGUSR2, signalhandler);
	while (1)
	{
		pause();
	}
}
