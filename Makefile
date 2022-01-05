# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 02:15:19 by bgoncalv          #+#    #+#              #
#    Updated: 2022/01/03 03:41:53 by bgoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		= -Wall -Wextra -Werror
LIBFT		= -L./libft -lft

SERVER_SRCS	= ft_server.c
CLIENT_SRCS	= ft_client.c
SRCS		= $(SERVER_SRCS) / $(CLIENT_SRCS)
SERVER_OBJS	= ${SRCS:.c=.o}
CLIENT_OBJS	= ${SRCS:.c=.o}

SERVER		= server
CLIENT		= client

RM			= rm -f

_BLUE=\e[34m
_PURPLE=\e[35m
_CYAN=\e[36m
_END=\e[0m

$(SERVER):
			@$(MAKE) -C ./libft
			@$gcc $(FLAGS) $(LIBFT) $(SERVER_SRCS) -o $(SERVER)
			@printf "server		[$(_BLUE)✓$(_END)]\n"

$(CLIENT):
			@$(MAKE) -C ./libft
			@$gcc $(FLAGS) $(LIBFT) $(CLIENT_SRCS) -o $(CLIENT)
			@printf "client		[$(_BLUE)✓$(_END)]\n"

all :
			@$(MAKE) -C ./libft
			@$gcc $(FLAGS) $(LIBFT) $(SERVER_SRCS) -o $(SERVER)
			@printf "server		[$(_BLUE)✓$(_END)]\n"
			@$gcc $(FLAGS) $(LIBFT) $(CLIENT_SRCS) -o $(CLIENT)
			@printf "client		[$(_BLUE)✓$(_END)]\n"

re:			clean
			@$(MAKE) -C ./libft
			@$gcc $(FLAGS) $(LIBFT) $(CLIENT_SRCS) -o $(CLIENT)
			@printf "client		[$(_BLUE)✓$(_END)]\n"
			@$gcc $(FLAGS) $(LIBFT) $(SERVER_SRCS) -o $(SERVER)
			@printf "server		[$(_BLUE)✓$(_END)]\n"

clean :
			@$(MAKE) fclean -C ./libft
			@rm -rf $(SERVER) $(CLIENT) *.o
			@printf "$(_PURPLE)server		deleted$(_END)\n"
			@printf "$(_PURPLE)client		deleted$(_END)\n"

fclean :	clean
			
PHONY : 	re all clean fclean