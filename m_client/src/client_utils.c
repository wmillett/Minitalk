/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:49:52 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/11 21:39:25 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sort_time(int len)
{
	int	time;

	if (len <= 1000)
		time = 50;
	else if (len <= 10000)
		time = 100;
	else if (len <= 50000)
		time = 250;
	else if (len <= 100000)
		time = 350;
	else
		time = 450;
	return (time);
}
