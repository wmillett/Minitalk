/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:53:31 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 20:54:41 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	check_args(int argc, char **argv)
{
	if (argc != 1 || argv[1])
	{
		printf("\033[1;31mWrong number of arguments.\033[0m\n");
		exit(0);
	}
	set_toreset();
}

int	print_string(char *str, int len)
{
	write(2, str, len);
	write(2, "\n", 1);
	free(str);
	set_toreset();
	return (0);
}
