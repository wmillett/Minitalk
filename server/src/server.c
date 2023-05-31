/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:51:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/30 20:42:10 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <stdio.h>
#include <signal.h>

// void print_string()
// {


	
// }








void signalHandler(int signal) 
{
	int i;

	i = 7;
	while(i)
	{
    	if (signal == SIGUSR1)
			printf("1\n");
    	else if (signal == SIGUSR2)
			printf("0\n");
		i--;
	}
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
		printf("ok\n");
	}
}
