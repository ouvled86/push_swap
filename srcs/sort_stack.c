/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/17 04:33:33 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    set_tarpos(t_stack **stack)
{
    int i;
	int v;
	int s;
    t_stack *max;
    t_stack *temp;

    i = 1;
	s = stack_size_setpos(stack);
    while (s-- > 0)
    {
	    temp = *stack;
		v = 0;
	    while (temp)
        {
			if (v < temp->value && temp->tarpos == 0)
			{
				max = temp;
				v = temp->value;
			}
			temp = temp->next;
        }
		max->tarpos = i;
		i++;
	}
}