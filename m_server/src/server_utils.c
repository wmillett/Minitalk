/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:34:21 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/11 21:42:16 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

int	print_string(char *str, int len)
{
	write(2, str, len);
	write(2, "\n", 1);
	free(str);
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
