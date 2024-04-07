NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/push_swap.c srcs/stack_utils.c srcs/error_management.c srcs/push_op.c srcs/reverse_rotate_op.c srcs/rotate_op.c srcs/swap_op.c srcs/sort_stack.c
OBJS = $(SRCS:.c=.o)
LIBFTPRINTF = libft/libft_printf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

$(LIBFTPRINTF): includes/libft.h
	make -C libft/

%.o: %.c includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	rm -rf $(OBJS)

fclean:
	make fclean -C libft/
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: clean fclean