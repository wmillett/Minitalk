/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 18:09:11 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_sigpid
{
	pid_t	pid;
	int		tick;
	int		active;

}			t_sigpid;

//server
int			sort_string(int binary[8], int check_reset);
void		signalhandler(int signal, siginfo_t *info, void *context);
void 		form_char(int signal);
//server_utils
int 		free_quit(char *tofree, int len, int type);
char		btoa(int binary[8]);
int			sort_mem(int type, char *copy, char *str, int len);
// int			handle_reset(char *str, int len);
void		reset_server(void);
#endif
