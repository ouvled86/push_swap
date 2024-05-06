/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/06 13:26:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	push_range(t_stack **a, t_stack **b)
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
