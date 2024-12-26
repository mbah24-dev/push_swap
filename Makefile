NAME      ?= exec
CC         = cc
DIR        = src
INC        = inc
CFLAGS     = -Wall -Werror -Wextra -I ./
HEADER     = $(INC)/push_swap.h 
SRC        = $(DIR)/app/app.error.c $(DIR)/app/app.utils.c $(DIR)/app/app.ft_split.c \
			 $(DIR)/app/app.stack_op_rotate.c $(DIR)/app/app.stack_op_swap_push.c $(DIR)/app/app.parse_argv.c \
			 $(DIR)/app/app.init_stack.c $(DIR)/app/app.sort_large_stacks_utils.c $(DIR)/app/app.sort_large_stacks.c \
			 $(DIR)/app/app.ft_itoa.c $(DIR)/app/app.stack_sort_small_utils.c $(DIR)/app/app.sort_small_stack.c \
			 $(DIR)/main.c 

OBJS       = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
