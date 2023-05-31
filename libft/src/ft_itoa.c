/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:39:29 by wmillett          #+#    #+#             */
/*   Updated: 2023/01/25 18:58:58 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_createnbr(long n, int *i, char *str)
{
	if (n > 9)
	{
		ft_createnbr(n / 10, i, str);
		ft_createnbr(n % 10, i, str);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	n2;

	n2 = n;
	i = 0;
	dest = ft_calloc(sizeof (char), (ft_count(n2) + 1));
	if (!dest)
		return (NULL);
	if (n2 < 0)
	{
		n2 *= -1;
		dest[i++] = '-';
	}
	ft_createnbr(n2, &i, dest);
	return (dest);
}
