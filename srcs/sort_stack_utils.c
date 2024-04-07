/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:54:26 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/07 22:04:31 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int locate_pb(t_stack **a, t_stack **b)
{
    t_stack *temp;

    temp = *b;
    while (temp->tarpos != (*a)->tarpos - 1)
        temp = temp->next;
    return(temp->first_half);
}

int bottom_a(t_stack **a)
{
    t_stack *temp;

    temp = last_node(*a);
    return (temp->tarpos);
}