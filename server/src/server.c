/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/02 22:20:36 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

pid_t sender_pid;

static void print_string(char* str)
{
	printf("%s\n", str);
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
	return(c);
}

static void sort_string(int binary[8])
{
	static char* str;
	static int len;
	static char* temp;
	char c;
	int j;
	
	if (!len)
	{
		len = 0;
		str = (char*)malloc(sizeof((char) + 110000000));
	}
	// if (len && len % 10 == 0)
	// {
	// 	temp = str;
	// 	free(temp);
	// 	str = (char*)malloc(sizeof((char) + (len + (len / 10) + 11)));
	// }
		str[len] = btoa(binary);
		if (str[len] == '\0')
			print_string(str);
		// else
		// 	write(2,&str[len], 1);
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

	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
	while(1)
	{
		pause();
	}
}
