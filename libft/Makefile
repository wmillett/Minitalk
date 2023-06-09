# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 11:55:15 by wmillett          #+#    #+#              #
#    Updated: 2023/06/09 16:44:43 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar -crs
MK = mkdir -p
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCDIR = inc
SRCDIR = src

SRC =	ft_strlen.c\
		ft_atoi.c\
		ft_strncpy.c\

VPATH = ${SRCDIR}
OBJDIR = obj
OBJS = $(addprefix ${OBJDIR}/, ${SRC:%.c=%.o})

${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@$(AR) $(NAME) $(OBJS)
$(OBJDIR):
	@$(MK) $(OBJDIR)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.phony: all clean fclean re