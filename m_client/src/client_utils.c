/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:49:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/21 23:48:16 by lightyagami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	sort_time(int len)
{
	int	time;

	if (len <= 1000)
		time = 50;
	else if (len <= 10000)
		time = 100;
	else if (len <= 50000)
		time = 250;
	else if (len <= 100000)
		time = 350;
	else
		time = 450;
	return (time);
}

void	sendsignal(pid_t serv_pid, int signal_number, int time)
{
	int	i;

	if (!signal_number)
	{
		i = 8;
		while (i--)
		{
			kill(serv_pid, SIGUSR1);
			usleep(time);
		}
	}
	else
		kill(serv_pid, signal_number);
	usleep(time);
}

void print_prog(int count)
{
	if (count == 0)
	{
		printf("\033[1;35mServer connection established.\033[0m\n");
		printf("\033[38;5;130m[%i%%]\033[0m\n", count);
	}
	if (count == 10)
		printf("\033[38;5;220m[%i%%]\033[0m\n", count);
	if (count == 20)
		printf("\033[38;5;184m[%i%%]\033[0m\n", count);
	if (count == 30)
		printf("\033[33m[%i%%]\033[0m\n", count);
	if (count == 40)
		printf("\033[38;5;226m[%i%%]\033[0m\n", count);
	if (count == 50)
		printf("\033[38;5;154m[%i%%]\033[0m\n", count);
	if (count == 60)
		printf("\033[38;5;112m[%i%%]\033[0m\n", count);
	if (count == 70)
		printf("\033[38;5;82m[%i%%]\033[0m\n", count);
	if (count == 80)
		printf("\033[38;5;46m[%i%%]\033[0m\n", count);
	if (count == 90)
		printf("\033[38;5;40m[%i%%]\033[0m\n", count);
	if (count == 100)
		printf("\033[1;32m[%i%%]\033[0m\n", count);
}
