/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/08 01:28:39 by ouel-bou         ###   ########.fr       */
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
	int			p1;
	int			p2;
	int			t;
	static int	c;

	p1 = ((((*a)->size - 1) / 3));
	p2 = p1 / 2;
	t = ((((*a)->size - 1) / 3));
	while ((*a)->size > 3)
	{
		if (*b && (*b)->tarpos <= p2 && (*b)->size > 1)
			rb(b);
		if ((*a)->tarpos < p1)
		{
			pb(a, b);
			c++;
		}
		else
			ra(a);
		if (c >= p1)
		{
			p1 += ((*a)->size - 1) / 2;
			p2 += ((*a)->size - 1) / 2;
		}	
	}
}
// void    push_chunks(t_stack **a, t_stack **b)
// {
//     int            p1;
//     int             lastp1;
//     int            p2;

//     p1 = ((*a)->size - 1) / 3;
//     p2 = p1 / 2;
//     lastp1 = -1;
//     while ((*a)->size > 3)
//     {
//         if (*b && (*b)->size > 1 && (*b)->tarpos >= lastp1 && (*b)->tarpos <= p2)
//             rb(b);
//         if ((*a)->tarpos < p1)
//             pb(a, b);
//         else
//             ra(a);
//         if ((*b)->size == p1)
//         {
//             lastp1 = p1;
//             p1 += ((*a)->size - 1) / 2;
//  			p2 += ((*a)->size - 1) / 2;
//         }    
//     }
// }

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

void	push_back(t_stack **a, t_stack **b)
{
    int    a_bot;

    a_bot = bottom_a(a);
    while (b && *b)
    {
        if (*b && locate_pb(a, b) == 1)
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
        else if (*b && locate_pb(a, b) == 0)
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
        while((*b) && (*b)->tarpos == (*a)->tarpos - 1)
            pa(a, b);
        while (bottom_a(a) == (*a)->tarpos - 1)
            rra(a);
    }
}
