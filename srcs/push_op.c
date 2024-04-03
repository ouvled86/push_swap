/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:49:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 22:53:28 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int pop(t_stack **stack)
{
    int value;
    t_stack *temp;

    if (!*stack)
        return (ft_printf("Stack Underflow\n"), 0);
    temp = *stack;
    value = temp->value;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
    return (value);
}

void push(t_stack **stack, int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        err_func(stack, NULL, "Error");
    node->value = value;
    node->next = *stack;
    node->prev = NULL;
    if (*stack)
        (*stack)->prev = node;
    *stack = node;
}

void pa(t_stack **a, t_stack **b)
{
    if (!*b)
        return ;
    push(a, pop(b));
    ft_printf("pa\n");
    stack_size_setpos(a);
    stack_size_setpos(b);
}

void pb(t_stack **a, t_stack **b)
{
    if (!*a)
        return ;
    push(b, pop(a));
    ft_printf("pb\n");
    stack_size_setpos(a);
    stack_size_setpos(b);
}
