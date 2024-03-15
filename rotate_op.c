/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 19:22:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rot(t_stack **stack)
{
    t_stack *temp;
    t_stack *holder;

    if (!*stack || !(*stack)->next)
        exit(1);
    holder = *stack;
    temp = last_node(*stack);
    holder->prev = temp;
    holder->next = NULL;
    temp->next = holder;
    *stack = temp;
    stack_size_setpos(stack);
}

void ra(t_stack **a)
{
    rot(a);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    rot(b);
    ft_printf("rb\n");
}

void rr(t_stack **a, t_stack **b)
{
    rot(a);
    rot(b);
    ft_printf("rr\n");
}