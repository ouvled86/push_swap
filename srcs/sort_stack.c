/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/05 22:49:47 by codespace        ###   ########.fr       */
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
	static int	c;
	int	t;

	p1 = ((*a)->size - 1) / 3;
	p2 = p1 / 2;
	t = ((*a)->size - 1) / 3;
	while ((*a)->size > 3)
	{
		if ((*a)->tarpos < p1)
		{
			pb(a, b);
			c++;
		}
		else
			ra(a);
		if (*b && (*b)->tarpos < p2 && (*b)->size > 1)
			rb(b);
		if (c >= p1)
		{
			p2 += t;
			p1 += t;
		}	
	}
}

int	is_sorted(t_stack **a)
{
	t_stack	*temp;
	int		f;
	int		v;
	
	temp = *a;
	f = 1;
	while (temp->next)
	{
		v = temp->next->value;
		if (v < temp->value)
			f = 0;
		temp = temp->next;
	}
	return (f);
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

void push_back (t_stack **a, t_stack **b)
{
	t_stack	*temp;

	while (*b)
	{
		temp = *b;
		while (temp->tarpos == (temp->size - 1))
			temp = temp->next;
		if (temp->first_half == 1 && temp->size > 1)
		{
			while ((*b)->tarpos == ((*b)->size - 1))
				rb(b);
		}
		else if (temp->first_half == 0 && temp->size > 1)
		{
			while ((*b)->tarpos == ((*b)->size - 1))
				rrb(b);
		}
		pa(a, b);
	}
}

// Add is_sorted to check if list is sorted. DONE!
// Add tiny sort to sort last 3 elements. DONE!
// Add push_back, fix first_half when a node is pushed to b.
// (temp = *b); While temp->tarpos == temp->size -1
// if (temp->firsthalf == 1); rb til (*b)->tarpos == (*b)->size -1; pa
// if (temp->firsthalf == 0); rrb til (*b)->tarpos == (*b)->size -1; pa
// temp = temp->next;
