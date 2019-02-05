# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 15:46:50 by vkhomenk          #+#    #+#              #
#    Updated: 2019/02/03 18:49:11 by vkhomenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= fillit
SRC_DIR			:= src/
INC_DIR 		:= inc/
OBJ_DIR 		:= obj/
LIB_DIR			:= lib/

SRC				:= main.c read_file.c help_funcs.c fillit.c 
OBJ				:= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT			:= $(LIB_DIR)libft.a
LIBFT_DIR		:= $(LIB_DIR)libft/
LIBFT_INC		:= $(LIBFT_DIR)includes/

LIBFT_FLAGS 	:=  -lft -L $(LIBFT_DIR)
CC_FLAGS		:= -Wall -Wextra -Werror
LINK_FLAGS		:= $(LIBFT_FLAGS)
HEADER_FLAGS	:= -I $(INC_DIR)  -I $(LIBFT_INC)
CC				:= clang

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LINK_FLAGS)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -o $@ -c $< $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
