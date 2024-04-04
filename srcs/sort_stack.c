/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/04 00:48:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    set_tarpos(t_stack **stack)
{
    int i;
	int v;
	int s;
    t_stack *min;
    t_stack *temp;

    i = 0;
	s = stack_size_setpos(stack);
    while (s-- >= 0)
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
	int s;
	int	p1;
	int	p2;
	int	c;

	s = stack_size_setpos(a) - 1;
	p1 = s / 3;
	p2 = p1 / 2;
	c = 0;
	while (c <= p1)
	{
		ft_printf("p1 is %d\n", p1);
		if (*b && (*b)->tarpos <= p2 && (*b)->size > 1)
			rb(b);
		if ((*a)->tarpos <= p1)
		{
			pb(a, b);
			c++;
		}
		else
			ra(a);
	}
}
