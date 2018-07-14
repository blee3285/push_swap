# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blee <blee@student.42.us.org>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 14:11:04 by blee              #+#    #+#              #
#    Updated: 2018/07/13 18:31:10 by blee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC_DIR1 = ./srcs1
SRC_DIR2 = ./srcs2
OBJ_DIR1 = ./objs1
OBJ_DIR2 = ./objs2
LIBFT = ./libft/libft.a


SRC_FILES1 = main.c \
			 init_lst.c \
			 check_args.c \
			 int_size.c \
			 check_order.c \
			 push.c \
			 rotate.c \
			 rrotate.c \
			 swap.c \
			 small_sorts.c \
			 small_sorts2.c \
			 med_sort.c \
			 big_sort.c \
			 big_sort2.c

SRC_FILES2 = main.c \
			 init_lst.c \
			 check_args.c \
			 cmds.c \
			 swap.c \
			 push.c \
			 rotate.c \
			 rrotate.c \
			 read_cmds.c \
			 print_lst.c \
			 int_size.c

SRCS1 = $(addprefix $(SRC_DIR1)/, $(SRC_FILES1))
OBJS1 = $(addprefix $(OBJ_DIR1)/, $(SRC_FILES1:.c=.o))
SRCS2 = $(addprefix $(SRC_DIR2)/, $(SRC_FILES2))
OBJS2 = $(addprefix $(OBJ_DIR2)/, $(SRC_FILES2:.c=.o))

all: $(NAME1) $(NAME2)

$(LIBFT):
	make -C libft

$(OBJ_DIR1):
	mkdir -p $(OBJ_DIR1)

$(OBJ_DIR2):
	mkdir -p $(OBJ_DIR2)

$(OBJS1): $(OBJ_DIR1)/%.o: $(SRC_DIR1)/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I ./includes

$(OBJS2): $(OBJ_DIR2)/%.o: $(SRC_DIR2)/%.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I ./includes

$(NAME1): $(OBJ_DIR1) $(OBJS1) $(LIBFT)
	gcc -o $(NAME1) $(OBJS1) $(LIBFT)

$(NAME2): $(OBJ_DIR2) $(OBJS2) $(LIBFT)
	gcc -o $(NAME2) $(OBJS2) $(LIBFT)

clean:
	rm -rf $(OBJ_DIR1) $(OBJ_DIR2)
	make clean -C libft

fclean: clean
	rm -f $(NAME1) $(NAME2)
	make fclean -C libft

re: clean all
