/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/05 16:05:45 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

pid_t sender_pid;

static void print_string(char* str, int len)
{
	write(2, str, (len + 1));
	write(2, "\n", 1);
	// printf("%s\n", str);
}

static char btoa(int binary[8])
{
	int j;
	char c;
	
	c = 0;
	j = 0;
	while (j < 8)
	{
   		c |= (binary[j] & 1) << j;
		j++;
	}
	// printf("c: %c\n", c);
	return(c);
}

static void sort_string(int binary[8])
{
	static char* str;
	static int len;
	static char *copy;
	// t_mem *list;
	
	if (!len)
	{
		len = 0;
		str = (char*)malloc(sizeof((char) + 1));
		// list = malloc(sizeof(t_mem*));
	}
	else
	{
		copy = (char*)malloc(sizeof((char) + (len + 1)));
		ft_strlcpy(copy, str, (len + 1));
		free(str);
		str = (char*)malloc(sizeof((char) + (len + 2)));
		ft_strlcpy(str, copy, (len + 1));
	}

	// if (len && len % 10 == 0)
	// {
	// 	temp = str;
	// 	free(temp);
	// 	str = (char*)malloc(sizeof((char) + (len + (len / 10) + 11)));
	// }
	str[len] = btoa(binary);
	if (str[len] == '\0')
	{
		print_string(str, len);
		free(str);
		len = 0;
		return ;
	}
	// else
	// 	write(2,&str[len], 1);
	// printf("len: %i\n", len);
	len++;
}

void signalhandler(int signal)
{
	static int i;
	static int binary[8];
	
	if(!i)
		i = 8;
    if (signal == SIGUSR1)
		binary[--i] = 1;
    else if (signal == SIGUSR2)
		binary[--i] = 0;
	if (!i)
		sort_string(binary);
}

int main(int argc, char** argv)
{
	pid_t serv_pid;

	if (argc != 1 || argv[1])
		exit(0);
	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
	while(1)
	{
		pause();
	}
}
