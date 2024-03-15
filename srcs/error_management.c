/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:50:08 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 03:50:09 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    err_func(t_stack **stack, char **argv, char *display_msg)
{
    t_stack *temp;

    ft_printf("%s\n", display_msg);
    if (stack && *stack)
    {
        temp = *stack;
        while (temp)
        {
            temp = temp->next;
            free(*stack);
            *stack = temp;
        }
    }
    if (argv && *argv)
        argv = freemem(argv);
}