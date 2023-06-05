/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:15:48 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/05 15:36:48 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	r;

	if (!dst || !src)
		return (0);
	i = 0;
	r = ft_strlen(src);
	while (i < dstsize)
	{
		if (!src[i])
		{
			dst[i] = '\0';
			break ;
		}
		else
			dst[i] = src[i];
		++i;
	}
	if (i == dstsize)
		--i;
	if (dstsize)
		dst[i] = 0;
	return (r);
}
