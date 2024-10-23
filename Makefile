# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 18:48:15 by fmalungo          #+#    #+#              #
#    Updated: 2024/09/23 12:09:11 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = f
NAME_B = b

NAME_SERVER = server

NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus

NAME_CLIENT_BONUS = client_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

LIBFT = ./libft/libft.a

SOURCE_S = ./server.c

SOURCE_C = ./client.c

SOURCE_S_B = ./server_bonus.c

SOURCE_C_B = ./client_bonus.c

OBJ_S = $(SOURCE_S:.c=.o)

OBJ_C = $(SOURCE_C:.c=.o)

OBJ_S_B = $(SOURCE_S_B:.c=.o)

OBJ_C_B = $(SOURCE_C_B:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_S) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_S) $(LIBFT) -o server

$(NAME_CLIENT): $(OBJ_C) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_C) $(LIBFT) -o client

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_S_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_S_B) $(LIBFT) -o server_bonus

$(NAME_CLIENT_BONUS): $(OBJ_C_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_C_B) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_S)
	$(RM) $(OBJ_C)
	$(RM) $(OBJ_S_B)
	$(RM) $(OBJ_C_B)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME_SERVER)
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER_BONUS)
	$(RM) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY:	all bonus clean fclean re
