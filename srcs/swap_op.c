/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:32:43 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 22:53:28 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void swap(t_stack **stack)
{
    t_stack *temp;
    t_stack *holder;

    if (!*stack || !(*stack)->next)
        exit(1);
    holder = (*stack)->next;
    temp = *stack;
    if (holder->next)
    {
        holder->next->prev = temp;
        temp->next = holder->next;
    }
    else
        temp->next = NULL;
    holder->prev = NULL;
    holder->next = temp;
    temp->prev = holder;
    *stack = holder;
    stack_size_setpos(stack);
}

void sa(t_stack **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}