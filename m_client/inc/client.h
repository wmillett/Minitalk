/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:03 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 23:49:06 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../libft/inc/libft.h"
# include <signal.h>

typedef struct s_handle_pid
{
	int	initm;
	int	len;
}		t_handle_pid;

// client_utils
int		sort_time(int len);
void	sendsignal(pid_t serv_pid, int signal_number, int time);
#endif
