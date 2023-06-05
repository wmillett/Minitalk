/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/05 14:53:50 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../libft/inc/libft.h"

typedef struct s_mem
{
	char *c;
	struct t_mem *next;
}				t_mem;

#endif
