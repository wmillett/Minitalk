/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:10 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/30 20:40:23 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"


static void atob(pid_t serv_pid, char *str)
{
	int bit;
	int i;

	i = 0;
	while(str[i])
	{
		bit = 7;
		while(bit)
		{
			if ((str[i] >> bit) & 1 == 1)
				kill(serv_pid, SIGUSR1);
			else
				kill(serv_pid, SIGUSR2);
		}
		
	}
	
}


static void handle_exit(int type)
{
	write(2, "\033[1;31m", 7);
	if (type == 1)
		printf("Wrong number of arguments.\n");
	write(2, "\033[0m", 4);
	exit(0);
}

int main(int argc, char** argv)
{
	pid_t serv_pid;

	if (argc != 3)
		handle_exit(1);
	serv_pid = ft_atoi(argv[1]);
	atob(serv_pid, argv[2]);
	
}
