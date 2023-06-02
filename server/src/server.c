/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/01 21:35:45 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

pid_t sender_pid;

// static void btoa(int binary)
// {
//     char c;
// 	int i;

// 	i = 0;
// 	c = 0;
// 	while (i < 8)
// 	{
//         c |= (binary & 1) << i;
// 		i++;
// 	}
//     printf("%c", c);
// }

static void print_string(int code)
{
	static char* str;
	static int binary[8];
	static int i;
	
	// printf("ok\n");
	char c; //rm
	int j; //rm
	
	if (!i)
		i = 8;
	if (!str)
		str = 0;
	binary[--i] = code;
	if (!i)
	{
		j = 0;
		c = 0;
		while (j < 8)
		{
   	   		c |= (binary[j] & 1) << j;
			j++;
		}
		if (c == '\0')
			printf("\n");
		else
			printf("%c\n", c);
	}
		
}


void signalHandler(int signal)
{
	static int i;
	if(!i)
		i = 8;
    if (signal == SIGUSR1)
		print_string(1);
    else if (signal == SIGUSR2)
		print_string(0);
	// if (signal == SIGUSR1)
	// 	printf("1");
    // else if (signal == SIGUSR2)
	// 	printf("0");
	i--;
	// if (!i)
	// 	printf("\n");
}

int main(int argc, char** argv)
{
	pid_t serv_pid;

	serv_pid = getpid();
	printf("Server PID: %i\n", serv_pid);
	signal(SIGUSR1, signalHandler);
    signal(SIGUSR2, signalHandler);
	while(1)
	{
		pause();
	}
}
