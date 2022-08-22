# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 15:28:08 by rkassouf          #+#    #+#              #
#    Updated: 2022/07/24 15:19:47 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc $(CFLAGS)
RM = rm -rf

SRCS_DIR = ./src
OBJS_DIR = ./obj
INCLUDES_DIR = ./includes

NAME = minitalk
NAMESRV = server
NAMECLT = client

SRV_FILES = server.c utils.c
SRV_OBJS_FILES = $(SRV_FILES:.c=.o)
SRV_OBJS = $(addprefix $(OBJS_DIR)/, $(SRV_OBJS_FILES))
B_SRV_FILES = server_bonus.c utils_bonus.c
B_SRV_OBJS_FILES = $(B_SRV_FILES:.c=.o)
B_SRV_OBJS = $(addprefix $(OBJS_DIR)/, $(B_SRV_OBJS_FILES))

CLT_FILES = client.c utils.c
CLT_OBJS_FILES = $(CLT_FILES:.c=.o)
CLT_OBJS = $(addprefix $(OBJS_DIR)/, $(CLT_OBJS_FILES))
B_CLT_FILES = client_bonus.c utils_bonus.c
B_CLT_OBJS_FILES = $(B_CLT_FILES:.c=.o)
B_CLT_OBJS = $(addprefix $(OBJS_DIR)/, $(B_CLT_OBJS_FILES))

INCLUDES_FILES = minitalk.h
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(INCLUDES_FILES))
B_INCLUDES_FILES = minitalk_bonus.h
B_INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(B_INCLUDES_FILES))

all: $(NAME)

bonus: server_bonus client_bonus

$(NAME): $(NAMESRV) $(NAMECLT)

$(NAMESRV): $(SRV_OBJS) $(INCLUDES)
	$(CC) -o $(NAMESRV) $(SRV_OBJS)

$(NAMECLT): $(CLT_OBJS) $(INCLUDES)
	$(CC) -o $(NAMECLT) $(CLT_OBJS)

server_bonus: $(B_SRV_OBJS) $(B_INCLUDES)
	$(CC) -o $(NAMESRV) $(B_SRV_OBJS)

client_bonus: $(B_CLT_OBJS) $(B_INCLUDES)
	$(CC) -o $(NAMECLT) $(B_CLT_OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES_DIR) $(INCLUDES)
	mkdir -p $(OBJS_DIR)
	$(CC) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAMESRV)
	$(RM) $(NAMECLT)

re: fclean all

.PHONY:	all clean fclean re bonus
