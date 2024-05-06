/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:49:16 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 03:49:16 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	add_node(t_stack **stack, int n)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = n;
	node->next = NULL;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		*stack = node;
	}
}

static int	check_range_rep(t_stack *stack, long n)
{
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack	*last_node(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_size_setpos(t_stack **stack)
{
	int		size;
	int		i;
	t_stack	*temp;

	size = 0;
	temp = *stack;
	while (temp)
	{
		temp->pos = size;
		temp = temp->next;
		size++;
	}
	temp = *stack;
	i = 0;
	while (temp)
	{
		if (i < ((size + 1) / 2))
			temp->first_half = 1;
		else
			temp->first_half = 0;
		temp->size = size;
		temp = temp->next;
		i++;
	}
	return (size);
}

void	ini_stack(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
		i++;
	i--;
	while (i >= 0)
	{
		n = ft_atoi(argv[i]);
		if (check_range_rep(*a, n))
		{
			err_func(a, argv);
			exit(1);
		}
		add_node(a, (int)n);
		i--;
	}
	if (*a)
		(*a)->size = stack_size_setpos(a);
}
