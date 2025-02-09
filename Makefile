# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 21:57:50 by mbah              #+#    #+#              #
#    Updated: 2025/02/09 14:06:03 by mbah             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      ?= push_swap
CC         = cc
DIR        = src
INC        = inc
CFLAGS     = -Wall -Werror -Wextra -I $(INC)
HEADER     = $(INC)/push_swap.h $(INC)/checker_bonus.h $(INC)get_next_line_bonus.h
SRC        = $(DIR)/app/app_stack_op_swap_push.c $(DIR)/app/app_init_stack.c $(DIR)/app/app_ft_itoa.c \
			 $(DIR)/app/app_stack_op_rotate.c $(DIR)/app/app_optimal_move.c $(DIR)/app/app_sort_large_stacks.c \
			 $(DIR)/app/app_stack_sort_small_utils.c $(DIR)/app/app_sort_large_stacks_utils.c $(DIR)/app/app_parse_argv.c \
			 $(DIR)/app/app_sort_small_stack.c $(DIR)/app/app_utils.c $(DIR)/app/app_error.c  $(DIR)/app/app_ft_split.c \
			 $(DIR)/main.c

OBJS       = $(SRC:.c=.o)

SRC_BONUS =	$(DIR)/app/app_error.c $(DIR)/app/app_utils.c $(DIR)/app/app_ft_split.c \
			$(DIR)/app/app_stack_op_rotate.c $(DIR)/app/app_stack_op_swap_push.c $(DIR)/app/app_parse_argv.c \
			$(DIR)/app/app_init_stack.c $(DIR)/app/app_sort_large_stacks_utils.c $(DIR)/app/app_sort_large_stacks.c \
			$(DIR)/app/app_ft_itoa.c $(DIR)/app/app_stack_sort_small_utils.c $(DIR)/app/app_sort_small_stack.c \
			$(DIR)/app/app_optimal_move.c \
			$(DIR)/app/app_checker_bonus/app_checker_bonus.c $(DIR)/app/app_checker_bonus/app_checker_push_op_bonus.c \
			$(DIR)/app/app_checker_bonus/app_checker_rot_op_bonus.c $(DIR)/app/app_checker_bonus/get_next_line_bonus.c \
			$(DIR)/app/app_checker_bonus/get_next_line_utils_bonus.c 

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
