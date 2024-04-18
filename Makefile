NAME = push_swap

BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/push_swap.c \
		srcs/stack_utils.c \
		srcs/push_op.c \
		srcs/swap_op.c \
		srcs/rotate_op.c \
		srcs/sort_stack.c \
		srcs/error_management.c \
		srcs/sort_stack_utils.c \
		srcs/reverse_rotate_op.c \
		srcs/sort_small_stack.c

SRCS_BONUS =	bonus/checker.c \
				srcs/swap_op.c \
				srcs/push_op.c \
				bonus/free_mem.c \
				srcs/rotate_op.c \
				srcs/sort_stack.c \
				srcs/stack_utils.c \
				srcs/error_management.c \
				srcs/sort_stack_utils.c \
				srcs/reverse_rotate_op.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFTPRINTF = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@echo "Compiling push_swap..."
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFTPRINTF) includes/checker.h
	@echo "Compiling checker..."
	@cc -g $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBFTPRINTF)

$(LIBFTPRINTF): includes/libft.h
	@echo "Archiving libftprintf..."
	@make -s -C libft/

%.o: %.c includes/push_swap.h
	@cc $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@make -s fclean -C libft/
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean:
	@echo "Cleaning object files and executable..."
	@make -s fclean -C libft/
	@rm -f $(NAME) $(BONUS_NAME) $(OBJS) $(OBJS_BONUS)

re: fclean all

.PHONY: clean fclean