/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:49:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/15 20:50:50 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*pop(t_stack **stack)
{
	t_data	*data;
	t_stack	*temp;

	if (!*stack)
		return (NULL);
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	temp = *stack;
	data->value = temp->value;
	data->tarpos = temp->tarpos;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
	return (data);
}

void	push(t_stack **stack, t_data *data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = data->value;
	node->tarpos = data->tarpos;
	node->next = NULL;
	node->prev = NULL;
	if (*stack)
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
}

void	pa(t_stack **a, t_stack **b)
{
	if (!*b)
		return ;
	push(a, pop(b));
	ft_printf("pa\n");
	if (*a)
		(*a)->size = stack_size_setpos(a);
	if (*b)
		(*b)->size = stack_size_setpos(b);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(b, pop(a));
	ft_printf("pb\n");
	if (*a)
		(*a)->size = stack_size_setpos(a);
	if (*b)
		(*b)->size = stack_size_setpos(b);
}
