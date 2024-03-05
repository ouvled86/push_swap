#include "push_swap.h"

void    err_func(t_stack **stack, char **argv, char *display_msg)
{
    t_stack *temp;

    ft_printf("%s\n", display_msg);
    if (stack && *stack)
    {
        temp = *stack;
        while (temp)
        {
            temp = temp->next;
            free(*stack);
            *stack = temp;
        }
    }
    if (argv && *argv)
        argv = freemem(argv);
}