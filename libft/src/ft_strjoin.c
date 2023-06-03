/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:20:44 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/02 22:16:38 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*res;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * (size));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = (s1[i]);
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = (s2[j++]);
	res[i] = '\0';
	return (res);
}
