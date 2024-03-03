#include "push_swap.h"

int check_range(long n)
{
    if (n > INT_MAX || n < INT_MIN)
        return (1);
    return(0);
}

int check_rep(t_stack **stack, long n)
{
    while (stack)
    {
        if (stack->value == n)
            return (1);
        stack = stack->next;
    }
    return (0);
}

t_stack *last_node(t_stack *stack)
{
    while (stack->next)
        stack = stack->next;
    return (stack);
}

void    add_node(t_stack **stack, int n)
{
    t_stack *node;
    t_stack *last;

    if (!stack)
        return ;
    node = malloc(sizeof(t_stack));
    if (!node)
        return ;
    node->value = n;
    node->next = NULL;
    if (!*stack)
        node->prev = NULL;
    else
    {
        last = last_node;
        last->next = node;
        node->prev = last;
    }
}

void    ini_stack(t_stack **a, char **argv)
{
    long    n;
    int     i;
    while(argv[i])
    {
        n = ft_atol(argv[i]);
        if (check_range(n))
            return(ft_printf("Range Error"), 1);
        if (check_rep(a, n))
            return(ft_printf("Duplicated Number"), 1);
        add_node(a, (int)n);
        i++;
    }
}