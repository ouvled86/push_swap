/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 00:28:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void rot(t_stack **stack)
{
    t_stack *temp;
    t_stack *holder;

    if (!*stack || !(*stack)->next)
        exit(1);
    holder = *stack;
    temp = last_node(*stack);
    holder->prev = temp;
    temp->next = holder;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    holder->next = NULL;
    (*stack)->size = stack_size_setpos(stack);
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