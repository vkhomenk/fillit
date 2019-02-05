# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 20:13:29 by vkhomenk          #+#    #+#              #
#    Updated: 2019/02/05 14:48:51 by vkhomenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
SRC			= ft_putnbr_fd.c ft_strmapi.c ft_putstr.c ft_isupper.c ft_islower.c\
			ft_strncat.c ft_atoi.c ft_putstr_fd.c ft_strncmp.c ft_bzero.c \
			ft_strcat.c ft_strncpy.c ft_memalloc.c ft_strchr.c ft_strnequ.c \
			ft_memccpy.c ft_strclr.c ft_strnew.c ft_isalnum.c ft_memchr.c \
			ft_strcmp.c ft_strnstr.c ft_isalpha.c ft_memcmp.c ft_strcpy.c \
			ft_strrchr.c ft_isascii.c ft_memcpy.c ft_strdel.c ft_strsplit.c \
			ft_isdigit.c ft_memdel.c ft_strdup.c ft_strstr.c ft_isprint.c \
			ft_memmove.c ft_strequ.c ft_strsub.c ft_memset.c ft_striter.c \
			ft_strtrim.c ft_itoa.c ft_putchar.c ft_striteri.c ft_putchar_fd.c \
			ft_strjoin.c ft_tolower.c ft_putendl.c ft_strlcat.c \
			ft_toupper.c ft_putendl_fd.c ft_strlen.c ft_putnbr.c \
			ft_strmap.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			ft_lstiter.c ft_lstmap.c ft_intiter.c ft_power.c ft_atoi_base.c \
			ft_itoa_base.c ft_nbrlen.c ft_nbrlen_base.c ft_matrixalloc.c \
			ft_matrixdel.c ft_swap.c
OBJ			= $(SRC:.c=.o)
INC_DIR		= includes/
CC			= clang
CC_FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CC_FLAGS) -o $@ -c $< -I $(INC_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
