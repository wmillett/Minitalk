/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/09 16:38:25 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/inc/libft.h"
# include <stdio.h>

typedef struct s_mem
{
	char			*c;
	struct t_mem	*next;
}					t_mem;
//server_utils
void				print_string(char *str, int len);
char				btoa(int binary[8]);
#endif
