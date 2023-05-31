# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/05/30 21:37:30 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Library Name ----------------------------
NAMEC = client.a
NAMES = server.a

#Dependencies -----------------------------
#Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MK = mkdir -p
RM = rm -rf
#Sources directories ----------------------
INCDIR = inc/
SRCDIR = src/
CLIENTDIR = client/
SERVERDIR = server/
LIBFT_A = libft.a
LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), $(LIBFT_A))
SERVER = $(addprefix $(SERVERDIR), $(NAMES))
CLIENT = $(addprefix $(CLIENTDIR), $(NAMEC))
VPATH = ${SRCDIR}
#Colours -----------------------------------
B_BLUE='\033[1;34m'
RED=\033[0;31m
B_GREEN=\033[1;32m
COLOUR_END=\033[0m
#Object directories ------------------------
OBJDIR = obj/
OBJS = $(addprefix ${OBJDIR}, ${SRC:%.c=%.o})
#Rules -------------------------------------
${OBJDIR}/%.o : %.c
	@${CC} ${FLAGS} -I${INCDIR} $< -o $@
all: $(NAMEC) $(NAMES)
$(LIBFT): 
	@make -C $(LIBFTDIR)
$(NAMEC): $(OBJS) $(LIBFT)
	@$(CC) ${FLAGS} $(OBJS) -L$(dir $(LIBFT)) -lft -o $(NAMEC)
	
	@echo "$(B_GREEN)Minitalk has been created 🦊$(COLOUR_END)!"
$(NAMES): $(OBJS) $(LIBFT)
$(OBJDIR_SERV):
	@$(MK) $(SERVERDIR) $(OBJDIR)
$(OBJDIR_CLIENT):
	@$(MK) $(CLIENTDIR) $(OBJDIR)
clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	
fclean: clean
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)Minitalk has been deleted 🗑️$(COLOUR_END)"
re: fclean all
.PHONY: all clean fclean re

