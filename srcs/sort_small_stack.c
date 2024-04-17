/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:12:44 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/17 19:00:13 by ouel-bou         ###   ########.fr       */
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
		sa(a);
	else if (v1 > v2 && v1 > v3 && v2 > v3)
	{
		sa(a);
		rra(a);
	}
	else if (v1 > v2 && v1 > v3 && v2 < v3)
		ra(a);
	else if (v1 > v3 && v2 > v1)
		rra(a);
	else if (v1 > v2 && v3 > v1)
		sa(a);
	else if (v1 < v2 && v3 < v2)
	{
		rra(a);
		sa(a);
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
			ra(a);
	}
	else
	{
		while ((*a)->value != find_min(a))
			rra(a);
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
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
			ra(a);
	}
	else
	{
		while ((*a)->value != find_min(a))
			rra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}
