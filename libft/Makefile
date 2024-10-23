# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalungo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 11:16:47 by fmalungo          #+#    #+#              #
#    Updated: 2024/05/18 11:16:51 by fmalungo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

AR = ar rcs

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
		ft_tolower.c ft_toupper.c

SRCS_B = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			 ft_lstlast.c ft_lstmap.c ft_lstnew.c  ft_lstsize.c

#OBJS will change .c in .o
OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
#this command mean take the OBJS and put into the NAME with the commands of AR
${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}

all: ${NAME}
#for the bonus part
bonus:	${NAME} ${OBJS_B}
	${AR} ${NAME} ${OBJS_B}
#The clean will remove all .o files
clean:
	${RM} ${OBJS} ${OBJS_B}
#The fclean will do the clean + remove the .a file
fclean: clean
	${RM} ${NAME}
#re will do fclean and he will do the make again
re : fclean all
