# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 15:28:08 by rkassouf          #+#    #+#              #
#    Updated: 2022/07/21 21:40:38 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
NAME_CLIENT		= client
NAME_SERVER		= server
NAME_CLIENT_B	= client_bonus
NAME_SERVER_B	= server_bonus

SRC_CLIENT		= client.c utils.c
SRC_SERVER		= server.c utils.c
SRC_CLIENT_B	= client_bonus.c utils_bonus.c
SRC_SERVER_B	= server_bonus.c utils_bonus.c

OBJ_CLIENT		= $(SRC_CLIENT:.c=.o)
OBJ_SERVER		= $(SRC_SERVER:.c=.o)
OBJ_CLIENT_B	= $(SRC_CLIENT_B:.c=.o)
OBJ_SERVER_B	= $(SRC_SERVER_B:.c=.o)

CC = gcc

FLAGS =  -Wall -Werror -Wextra

RM = /bin/rm -f

all:				$(NAME)

$(NAME):			$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER):		$(OBJ_SERVER)
					$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):		$(OBJ_CLIENT)
					$(CC) $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER_B):	$(OBJ_SERVER_B)
					$(CC) $(FLAGS) $(OBJ_SERVER_B) -o $(NAME_SERVER_B)

$(NAME_CLIENT_B):	$(OBJ_CLIENT_B)
					$(CC) $(FLAGS) $(OBJ_CLIENT_B) -o $(NAME_CLIENT_B)

bonus: $(NAME_CLIENT_B) $(NAME_SERVER_B)

clean:
		$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_B) $(OBJ_SERVER_B)

fclean: clean
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)

re: fclean all

.PHONY: all clean fclean re
