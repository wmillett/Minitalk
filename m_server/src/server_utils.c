/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:34:21 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 21:11:27 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int	free_quit(char *tofree, int len, int type)
{
	if (type == 1)
	{
		if (tofree)
			free(tofree);
		printf("\033[1;31mFailed memory allocation at '%i'.\033[0m\n", len);
		exit(1);
	}
	if (type == ERROR)
	{
		if (tofree)
			free(tofree);
	}
	return (0);
}

int	sort_mem(char *str)
{
	if (str == NULL)
	{
		printf("\033[1;31mFailed initial memory allocation.\033[0m\n");
		exit(1);
	}
	return (0);
}

char	btoa(int binary[8])
{
	int		j;
	char	c;

	c = 0;
	j = 0;
	while (j < 8)
	{
		c |= (binary[j] & 1) << j;
		j++;
	}
	return (c);
}

int	btoi(int binary[8])
{
	int	j;
	int	c;

	c = 0;
	j = 0;
	while (j < 8)
	{
		c |= (binary[j] & 1) << j;
		j++;
	}
	return (c);
}

void	reset_server(void)
{
	sort_string(NULL, ERROR);
	form_char(ERROR);
	printf("\033[1;31mServer has been reset due to inactivity.\033[0m\n");
}
