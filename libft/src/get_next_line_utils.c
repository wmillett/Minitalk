/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:31:37 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/24 15:20:59 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
	while (len--)
		((char *)b)[len] = 0;
}

void	*ft_sfree(void *str)
{
	if (str)
		free(str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;

	new = malloc(count * size);
	if (!new)
		return (NULL);
	ft_bzero(new, count * size);
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	else
		s2_len = 0;
	new = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (new == NULL)
		return (new = ft_sfree(new));
	while (s1_len + s2_len-- > s1_len)
		new[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		new[s1_len] = s1[s1_len];
	if (*new == '\0')
		new = ft_sfree(new);
	return (ft_sfree(s1), new);
}
