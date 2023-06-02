# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 08:48:00 by wmillett          #+#    #+#              #
#    Updated: 2023/06/01 17:21:29 by wmillett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Programs ----------------------------
NAMEC = client.a
NAMES = server.a
NAME = Minitalk
#Dependencies -----------------------------
LIBFT_A = libft.a
#Command variables ------------------------
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
MK = mkdir -p
RM = rm -rf
#Source files ----------------------
SRC_SERV = server.c
SRC_CLIENT = client.c
#Sources directories ----------------------
INCDIR = inc/
SRCDIR = src/
CLIENTDIR = client/
SERVERDIR = server/
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
OBJS_CLIENT = $(addprefix ${OBJDIR}, ${SRC_CLIENT:%.c=%.o})
OBJS_SERV = $(addprefix ${OBJDIR}, ${SRC_SERV:%.c=%.o})
#Rules -------------------------------------
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} $< -o $@
${OBJDIR}/client/obj/%.o : client/src/%.c
	@${CC} ${CFLAGS} -I${INCDIR} $< -o $@
${OBJDIR}/client/obj/%.o : client/src/%.c
	@${CC} ${CFLAGS} -I${INCDIR} $< -o $@
all: $(NAMEC) $(NAMES)
$(LIBFT): 
	@make -C $(LIBFTDIR)
$(NAMEC): $(OBJDIR_CLIENT) $(OBJS_CLIENT) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS_CLIENT) -L$(dir $(LIBFT)) -lft -o $(NAMEC)
	@echo "$(B_GREEN)Client program has been created 🦊$(COLOUR_END)!"
$(NAMES): $(OBJDIR_SERV) $(OBJS_SERV) $(LIBFT)
	@$(CC) ${CFLAGS} $(OBJS_SERV) -L$(dir $(LIBFT)) -lft -o $(NAMES)
	@echo "$(B_GREEN)Server program has been created 🦊$(COLOUR_END)!"
$(OBJDIR_SERV):
	@$(MK) $(SERVERDIR) $(OBJDIR)
$(OBJDIR_CLIENT):
	@$(MK) $(CLIENTDIR) $(OBJDIR)
clean:
	@$(RM) $(CLIENTDIR)$(OBJDIR)
	@$(RM) $(SERVERDIR)$(OBJDIR)
	@make -C $(LIBFTDIR) clean
fclean: clean
	@make -C $(LIBFTDIR) fclean
	@echo "$(RED)$(NAME) has been deleted 🗑️$(COLOUR_END)"
re: fclean all
.PHONY: all clean fclean re










# # Library Names
# NAMEC = client
# NAMES = server

# # Dependencies
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
# MK = mkdir -p
# RM = rm -rf

# # Directories
# INCDIR = inc/
# SRCDIR = src/
# CLIENTDIR = client/
# SERVERDIR = server/
# LIBFTDIR = libft/
# OBJDIR = obj/

# # Source Files
# CLIENTSRC = $(wildcard $(CLIENTDIR)*.c)
# SERVERSRC = $(wildcard $(SERVERDIR)*.c)

# # Object Files
# CLIENTOBJ = $(patsubst $(CLIENTDIR)%.c,$(OBJDIR)$(CLIENTDIR)%.o,$(CLIENTSRC))
# SERVEROBJ = $(patsubst $(SERVERDIR)%.c,$(OBJDIR)$(SERVERDIR)%.o,$(SERVERSRC))

# # Library
# LIBFT_A = libft.a
# LIBFT = $(LIBFTDIR)$(LIBFT_A)

# # Compilation
# all: $(NAMEC) $(NAMES)

# $(NAMEC): $(CLIENTOBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) -I$(CLIENTDIR)$(INCDIR) $(CLIENTOBJ) -L$(LIBFTDIR) -lft -o $@
# 	@echo "\033[1;32mClient program has been created 🦊\033[0m"

# $(NAMES): $(SERVEROBJ) $(LIBFT)
# 	$(CC) $(CFLAGS) -I$(SERVERDIR)$(INCDIR) $(SERVEROBJ) -L$(LIBFTDIR) -lft -o $@
# 	@echo "\033[1;32mServer program has been created 🦊\033[0m"

# $(OBJDIR)$(CLIENTDIR)%.o: $(CLIENTDIR)%.c | $(OBJDIR)$(CLIENTDIR)
# 	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# $(OBJDIR)$(SERVERDIR)%.o: $(SERVERDIR)%.c | $(OBJDIR)$(SERVERDIR)
# 	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# $(OBJDIR)$(CLIENTDIR):
# 	$(MK) $(OBJDIR)$(CLIENTDIR)

# $(OBJDIR)$(SERVERDIR):
# 	$(MK) $(OBJDIR)$(SERVERDIR)

# $(LIBFT):
# 	make -C $(LIBFTDIR)

# clean:
# 	$(RM) $(OBJDIR)
# 	make -C $(LIBFTDIR) clean

# fclean: clean
# 	$(RM) $(NAMEC) $(NAMES)
# 	make -C $(LIBFTDIR) fclean
# 	@echo "\033[0;31mClient and server programs have been deleted 🗑️\033[0m"
# re: fclean all
# .PHONY: all clean fclean re
