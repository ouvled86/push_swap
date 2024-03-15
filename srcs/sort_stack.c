/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 22:45:32 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_tarpos(t_stack **stack)
{
    int i;
	int v;
	int s;
    t_stack *max;
    t_stack *temp;

    i = 1;
	v = 0;
	s = stack_size_setpos(stack);
	max = NULL;
    temp = *stack;
    while (s)
    {
	    while (temp->next)
        {
            v = temp->next->value;
			if (v > temp->value)
				max = temp->next;
            temp = temp->next;
        }
		max->tarpos = i;
		i++;
		s--;
	}
}