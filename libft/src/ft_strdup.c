/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:27:33 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/28 11:57:24 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src, char *dst)
{
	int	i;
	int	n;

	if (src == NULL)
		return (NULL);
	n = ft_strlen((char *)src);
	dst = ft_calloc(sizeof(*dst), n);
	if (!dst)
		return (NULL);
	i = 0;
	while (((char *)src)[i] != '\0')
	{
		dst[i] = ((char *)src)[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
