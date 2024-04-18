/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:33:52 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/18 19:18:29 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rot(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*holder;

	if (!*stack || !(*stack)->next)
		return ;
	holder = *stack;
	temp = last_node(*stack);
	holder->prev = temp;
	temp->next = holder;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	holder->next = NULL;
	(*stack)->size = stack_size_setpos(stack);
}

void	ra(t_stack **a, int f)
{
	rot(a);
	if (f == 0)
		ft_printf("rb\n");
}

void	rb(t_stack **b, int f)
{
	rot(b);
	if (f == 0)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int f)
{
	rot(a);
	rot(b);
	if (f == 0)
		ft_printf("rr\n");
}
