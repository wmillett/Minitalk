/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:21:13 by wmillett          #+#    #+#             */
/*   Updated: 2023/05/28 19:29:28 by wmillett         ###   ########.fr       */
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

# define ERROR -1

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
char		*ft_strdup(char *src, char *dst);
char		*ft_itoa(int n);
int			ft_atoi(const char *str);
// void		*ft_sfree(void *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
#endif
