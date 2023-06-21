/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 21:11:17 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/inc/libft.h"
# include <signal.h>

typedef struct s_sigpid
{
	pid_t	pid;
	int		tick;
	int		active;
	int		len;

}			t_sigpid;

//server
int			sort_string(int binary[8], int type);
void		signalhandler(int signal, siginfo_t *info, void *context);
void		form_char(int signal);
void		set_toreset(void);
//server_exit
void		check_args(int argc, char **argv);
int			print_string(char *str, int len);
//server_utils
int			free_quit(char *tofree, int len, int type);
char		btoa(int binary[8]);
int			sort_mem(char *str);
int			btoi(int binary[8]);
void		reset_server(void);
#endif
