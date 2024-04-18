/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:32:43 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/18 19:20:39 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*holder;

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

void	sa(t_stack **a, int f)
{
	swap(a);
	if (f == 0)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int f)
{
	swap(b);
	if (f == 0)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int f)
{
	swap(a);
	swap(b);
	if (f == 0)
		ft_printf("ss\n");
}
