/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:32:03 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/22 01:11:35 by lightyagami      ###   ########.fr       */
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
void 	print_prog(int count, int len);
#endif
