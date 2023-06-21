# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/06/20 20:59:29 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Programs ----------------------------
NAMEC = client
NAMES = server
NAME = Minitalk
# Dependencies -----------------------------
LIBFT_A = libft.a
# Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MK = mkdir -p
RM = rm -rf
# Source files ----------------------
SRC_SERV = server.c server_utils.c server_exit.c
SRC_CLIENT = client.c client_utils.c
# Sources directories ----------------------
INCDIR = inc/
SRCDIR = src/
CLIENTDIR = m_client/
SERVERDIR = m_server/
LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), $(LIBFT_A))
SERVER = $(addprefix $(SERVERDIR), $(NAMES))
CLIENT = $(addprefix $(CLIENTDIR), $(NAMEC))
VPATH = ${SRCDIR}
# Colours -----------------------------------
B_BLUE='\033[1;34m'
RED=\033[0;31m
B_GREEN=\033[1;32m
COLOUR_END=\033[0m
# Object directories ------------------------
OBJDIR = obj/
OBJS_CLIENT = $(patsubst %.c,$(OBJDIR)$(CLIENTDIR)obj/%.o,$(SRC_CLIENT))
OBJS_SERV = $(patsubst %.c,$(OBJDIR)$(SERVERDIR)obj/%.o,$(SRC_SERV))
# Rules -------------------------------------
${OBJDIR}$(CLIENTDIR)obj/%.o: $(CLIENTDIR)$(SRCDIR)%.c
	@${CC} ${CFLAGS} -I${INCDIR} -c $< -o $@

${OBJDIR}$(SERVERDIR)obj/%.o: $(SERVERDIR)$(SRCDIR)%.c
	@${CC} ${CFLAGS} -I${INCDIR} -c $< -o $@

all: $(NAMEC) $(NAMES)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAMEC): $(OBJS_CLIENT) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS_CLIENT) -L$(dir $(LIBFT)) -lft -o $(NAMEC)
	@echo "$(B_GREEN)Client program has been created 💻$(COLOUR_END)!"

$(NAMES): $(OBJS_SERV) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS_SERV) -L$(dir $(LIBFT)) -lft -o $(NAMES)
	@echo "$(B_GREEN)Server program has been created 🖨 $(COLOUR_END)!"

$(OBJS_CLIENT): | $(OBJDIR)$(CLIENTDIR)obj
$(OBJS_SERV): | $(OBJDIR)$(SERVERDIR)obj

$(OBJDIR)$(CLIENTDIR)obj:
	@$(MK) $@

$(OBJDIR)$(SERVERDIR)obj:
	@$(MK) $@

clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(NAMEC) $(NAMES)
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)$(NAME) has been deleted 🗑️$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re