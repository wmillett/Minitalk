/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:21:13 by wmillett          #+#    #+#             */
/*   Updated: 2023/06/20 20:59:05 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

# define ERROR -1
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAILURE 0
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	len;
}			t_all;

int			ft_strlen(char *s);
int			ft_atoi(const char *str);
#endif
