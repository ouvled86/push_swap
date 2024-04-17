NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/push_swap.c srcs/stack_utils.c srcs/error_management.c srcs/push_op.c srcs/reverse_rotate_op.c srcs/rotate_op.c srcs/swap_op.c srcs/sort_stack.c srcs/sort_stack_utils.c srcs/sort_small_stack.c
OBJS = $(SRCS:.c=.o)
LIBFTPRINTF = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	cc -g $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

$(LIBFTPRINTF): includes/libft.h
	make -C libft/

%.o: %.c includes/push_swap.h
	cc -g $(CFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	rm -f $(OBJS)

fclean:
	make fclean -C libft/
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean fclean