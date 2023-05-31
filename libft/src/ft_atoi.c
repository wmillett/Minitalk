/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:12 by wmillett          #+#    #+#             */
/*   Updated: 2023/04/26 21:35:35 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	result;

	result = 0;
	i = 0;
	n = 0;
	while (str[n] == '\n' || str[n] == '\r' || str[n] == '\t' || str[n] == '\v'
		|| str[n] == ' ' || str[n] == '\f')
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			i++;
		n++;
	}
	while ((str[n] >= '0' && str[n] <= '9'))
		result = result * 10 + str[n++] - '0';
	if (i % 2 == 1)
		return (-result);
	return (result);
}
