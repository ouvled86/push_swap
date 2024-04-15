/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:54:26 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/15 20:53:23 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	locate_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	while (temp && temp->tarpos != (*a)->tarpos - 1)
		temp = temp->next;
	return (temp->first_half);
}

int	bottom_a(t_stack **a)
{
	t_stack	*temp;

	temp = last_node(*a);
	return (temp->tarpos);
}

void	rot_push(t_stack **a, t_stack **b, int a_bot)
{
	while (*b && (*b)->tarpos != (*a)->tarpos - 1)
	{
		if (a_bot == bottom_a(a) || (*b)->tarpos > bottom_a(a))
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
	}
}

void	revrot_push(t_stack **a, t_stack **b, int a_bot)
{
	while (*b && (*b)->tarpos != (*a)->tarpos - 1)
	{
		if (a_bot == bottom_a(a) || (*b)->tarpos > bottom_a(a))
		{
			pa(a, b);
			ra(a);
		}
		else
			rrb(b);
	}
}
