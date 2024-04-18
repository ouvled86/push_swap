/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:12:44 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/18 18:58:28 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack **a)
{
	t_stack	*t;
	int		min;

	t = (*a)->next;
	min = (*a)->value;
	while (t)
	{
		if (t->value < min)
			min = t->value;
		t = t->next;
	}
	return (min);
}

void	sort_three(t_stack **a)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = (*a)->value;
	v2 = (*a)->next->value;
	v3 = (*a)->next->next->value;
	if (v3 > v2 && v3 > v1 && v1 > v2)
		sa(a, 0);
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (v1 > v2 && v1 > v3 && v2 < v3)
		ra(a, 0);
	else if (v1 > v3 && v2 > v1)
		rra(a, 0);
	else if (v1 > v2 && v3 > v1)
		sa(a, 0);
	else if (v1 < v2 && v3 < v2)
	{
		rra(a, 0);
		sa(a, 0);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *a;
	while (t->value != find_min(a))
		t = t->next;
	if (t->first_half == 1)
	{
		while ((*a)->value != find_min(a))
			ra(a, 0);
	}
	else
	{
		while ((*a)->value != find_min(a))
			rra(a, 0);
	}
	pb(a, b, 0);
	sort_three(a);
	pa(a, b, 0);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*t;

	t = *a;
	while (t->value != find_min(a))
		t = t->next;
	if (t->first_half == 1)
	{
		while ((*a)->value != find_min(a))
			ra(a, 0);
	}
	else
	{
		while ((*a)->value != find_min(a))
			rra(a, 0);
	}
	pb(a, b, 0);
	sort_four(a, b);
	pa(a, b, 0);
}
