/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:34:21 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/09 16:36:01 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	print_string(char *str, int len)
{
	write(2, str, (len));
	write(2, "\n", 1);
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
