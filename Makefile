# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edechena <edechena@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 15:56:29 by edechena          #+#    #+#              #
#    Updated: 2023/07/25 14:57:42 by edechena         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		=	bsq

CC			=	gcc
RM			= 	rm -rf

CFLAGS		=	-Wall -Werror -Wextra

SRCSPATH 	=	./srcs/
OBJSPATH 	=	./objs/
INC 		=	./includes/
INCFILE 	=	./includes/bsq.h

SRCS 		=	utils/check_map.c\
				utils/free.c\
				utils/ft_putstr.c\
				utils/ft_strjoin_bsq.c\
				utils/init.c\
				display.c\
				main.c\
				process.c\
				read.c

SRCSNAME 	=	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME 	=	$(SRCSNAME:.c=.o)
OBJS 		=	$(addprefix $(OBJSPATH), $(OBJSNAME))

all: $(NAME)

$(NAME): $(OBJS) $(INCFILE)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Project compiled"

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJSPATH)
	@echo "Project cleaned"

clena: clean
	@echo " ┌────────┐"
	@echo " │ Clena! │"
	@echo " └────────┘"
	@echo "        \  ^__^"
	@echo "         \ (oo)\_______"
	@echo "           (__)\       )\\"
	@echo "               ||────w |"
	@echo "               ||     ||"

fclean:
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)
	@echo "Project all cleaned up"

re:	fclean all

.PHONY: all clean fclean re
