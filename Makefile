# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 21:57:50 by mbah              #+#    #+#              #
#    Updated: 2025/02/03 19:00:52 by mbah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      ?= push_swap
CC         = cc
DIR        = src
INC        = inc
CFLAGS     = -Wall -Werror -Wextra -I $(INC)
HEADER     = $(INC)/push_swap.h 
SRC        = $(DIR)/app/app.error.c $(DIR)/app/app.utils.c $(DIR)/app/app.ft_split.c \
			 $(DIR)/app/app.stack_op_rotate.c $(DIR)/app/app.stack_op_swap_push.c $(DIR)/app/app.parse_argv.c \
			 $(DIR)/app/app.init_stack.c $(DIR)/app/app.sort_large_stacks_utils.c $(DIR)/app/app.sort_large_stacks.c \
			 $(DIR)/app/app.ft_itoa.c $(DIR)/app/app.stack_sort_small_utils.c $(DIR)/app/app.sort_small_stack.c \
			 $(DIR)/app/app.optimal_move.c $(DIR)/main.c 

OBJS       = $(SRC:.c=.o)

SRC_BONUS =	$(DIR)/app/app.error.c $(DIR)/app/app.utils.c $(DIR)/app/app.ft_split.c \
			$(DIR)/app/app.stack_op_rotate.c $(DIR)/app/app.stack_op_swap_push.c $(DIR)/app/app.parse_argv.c \
			$(DIR)/app/app.init_stack.c $(DIR)/app/app.sort_large_stacks_utils.c $(DIR)/app/app.sort_large_stacks.c \
			$(DIR)/app/app.ft_itoa.c $(DIR)/app/app.stack_sort_small_utils.c $(DIR)/app/app.sort_small_stack.c \
			$(DIR)/app/app.optimal_move.c \
			$(DIR)/app/app.checker_bonus/app.checker_bonus.c $(DIR)/app/app.checker_bonus/app.checker_push_op_bonus.c \
			$(DIR)/app/app.checker_bonus/app.checker_rot_op_bonus.c $(DIR)/app/app.checker_bonus/get_next_line_bonus.c \
			$(DIR)/app/app.checker_bonus/get_next_line_utils_bonus.c 

CHECKER_HEADER = $(INC)/checker_bonus.h 
CHECKER        = checker
BONUS_OBJS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) $(CHECKER_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
bonus: $(NAME) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(CHECKER)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
