/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/16 23:06:59 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_tarpos(t_stack **stack)
{
	int		i;
	int		v;
	int		s;
	t_stack	*min;
	t_stack	*temp;

	i = 0;
	s = stack_size_setpos(stack);
	while (--s >= 0)
	{
		temp = *stack;
		v = INT_MAX;
		while (temp)
		{
			if (v > temp->value && !(temp->set))
			{
				min = temp;
				v = temp->value;
			}
			temp = temp->next;
		}
		min->tarpos = i;
		min->set = 1;
		i++;
	}
}

void	push_chunks(t_stack **a, t_stack **b)
{
	int	p1;
	int	p2;
	int	s;

	s = stack_size_setpos(a);
	p1 = 0;
	p2 = 30;
	while ((*a)->size > 3)
	{
		if (*b && (*b)->size > 1 && (*a)->tarpos < s - 3 && (*a)->tarpos <= p1)
		{
			pb(a, b);
			rb(b);
			p1++;
		}
		if ((*a)->tarpos < p1 + p2 && (*a)->tarpos < s - 3)
		{
			pb(a, b);
			p1++;
		}
		else
			ra(a); 
	}
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int		v;

	temp = *a;
	while (temp->next)
	{
		v = temp->next->value;
		if (v < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	lil_sort(t_stack **a)
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

void	push_back(t_stack **a, t_stack **b)
{
	int	a_bot;

	a_bot = bottom_a(a);
	while (b && *b)
	{
		if (b && *b && *b && locate_pb(a, b) == 1)
			rot_push(a, b, a_bot);
		else if (b && *b && locate_pb(a, b) == 0)
			revrot_push(a, b, a_bot);
		while (b && *b && (*b)->tarpos == (*a)->tarpos - 1)
		{
			pa(a, b);
		}
		while (bottom_a(a) == (*a)->tarpos - 1)
			rra(a);
	}
}
