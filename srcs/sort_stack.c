/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 21:59:50 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 23:22:26 by ouel-bou         ###   ########.fr       */
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
	max = NULL;
	v = temp->value;
	temp = *stack;
	s = stack_size_setpos(&temp);
	ft_printf("%d\n", s);
    while (s > 0)
    {
	    temp = *stack;
	    while (temp)
        {
            v = temp->value;
            temp = temp->next;
			if (v < temp->value && temp->tarpos == 0)
				max = temp;
        }
		if (max)
		{
			max->tarpos = i;
			ft_printf("||| %d |||\n", max->value);
		}
		i++;
		s--;
	}
}