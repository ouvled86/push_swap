/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 18:16:50 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *temp;
    t_stack *holder;

    if (!*stack || !(*stack)->next)
        exit(1);
    holder = *stack;
    temp = (*stack)->next;
    while (temp->next)
        temp = temp->next;
    holder->prev = temp;
    holder->next = NULL;
    temp->next = holder;
    *stack = temp;
    stack_size_setpos(stack);
}

void ra(t_stack **a)
{
    rotate(a);
}

void rb(t_stack **b)
{
    rotate(b);
}

void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
}