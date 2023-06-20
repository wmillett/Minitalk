/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:34:21 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 18:15:20 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int free_quit(char *tofree, int len, int type)
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
	return(0);
}

int	sort_mem(int type, char *copy, char *str, int len)
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
			free_quit(str, len, 1);
		ft_strncpy(copy, str, len + 1);
		free(str);
	}
	if (type == 3)
	{
		if (str == NULL)
			free_quit(copy, len, 1);
		ft_strncpy(str, copy, len + 1);
		free(copy);
	}
	return (len);
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

// int	handle_reset(char *str, int len)
// {
// 	(void)len;
// 	if (str)
// 		free(str);
// 	return (0);
// }

void	reset_server(void)
{
	sort_string(NULL, TRUE);
	form_char(ERROR);
	printf("\033[1;31mServer has been reset\033[0m\n");
}
