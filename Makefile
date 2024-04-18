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

SRCS_LIBFTPRINTF =	libft/ft_atoi.c \
					libft/ft_bzero.c \
    	    		libft/ft_calloc.c \
        			libft/ft_isalnum.c \
        			libft/ft_isalpha.c \
        			libft/ft_isascii.c \
   		     		libft/ft_isdigit.c \
	        		libft/ft_isprint.c \
       				libft/ft_memchr.c \
       			 	libft/ft_memcmp.c \
       				libft/ft_memcpy.c \
        			libft/ft_memmove.c \
       				libft/ft_memset.c \
					libft/ft_strncmp.c \
        			libft/ft_strchr.c \
        			libft/ft_strdup.c \
       				libft/ft_strlcat.c \
        			libft/ft_strlcpy.c \
        			libft/ft_strlen.c \
        			libft/ft_strnstr.c \
        			libft/ft_strrchr.c \
        			libft/ft_tolower.c \
        			libft/ft_toupper.c \
					libft/ft_itoa.c \
					libft/ft_split.c \
					libft/ft_strjoin.c \
					libft/ft_strmapi.c \
					libft/ft_substr.c \
					libft/ft_strtrim.c \
					libft/ft_striteri.c \
					libft/ft_putchar_fd.c \
					libft/ft_putstr_fd.c \
					libft/ft_putendl_fd.c \
					libft/ft_putnbr_fd.c \
					libft/ft_printf.c \
					libft/ft_printf_utils.c \
					libft/ft_printf_puts.c

SRCS_BONUS =	bonus/checker.c \
				bonus/free_mem.c \
				srcs/swap_op.c \
				srcs/push_op.c \
				srcs/rotate_op.c \
				srcs/sort_stack.c \
				srcs/stack_utils.c \
				srcs/error_management.c \
				srcs/sort_stack_utils.c \
				srcs/reverse_rotate_op.c \
				bonus/get_next_line/get_next_line.c \
				bonus/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_LIBFTPRINTF = $(SRCS_LIBFTPRINTF:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFTPRINTF = libft/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTPRINTF)
	@echo "Compiling push_swap..."
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFTPRINTF) includes/checker.h includes/get_next_line.h
	@echo "Compiling checker..."
	@cc $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBFTPRINTF)

$(LIBFTPRINTF): $(OBJS_LIBFTPRINTF)
	@echo "Archiving libftprintf..."
	@make -s -C libft/

%.o: %.c includes/push_swap.h includes/libft.h
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