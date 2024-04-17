NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/push_swap.c \
		srcs/stack_utils.c \
		srcs/error_management.c \
		srcs/push_op.c \
		srcs/reverse_rotate_op.c \
		srcs/rotate_op.c \
		srcs/swap_op.c \
		srcs/sort_stack.c \
		srcs/sort_stack_utils.c \
		srcs/sort_small_stack.c

OBJS = $(SRCS:.c=.o)

LIBFTPRINTF = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@echo "Compiling push_swap..."
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

$(LIBFTPRINTF): includes/libft.h
	@echo "Archiving libftprintf..."
	@make -s -C libft/

%.o: %.c includes/push_swap.h
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@make fclean -C libft/
	@rm -f $(OBJS)

fclean:
	@echo "Cleaning object files and executable..."
	@make fclean -C libft/
	@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: clean fclean