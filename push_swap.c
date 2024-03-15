/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:49:39 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 03:49:39 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    // atexit(leaks_checker);
    t_stack *a;
    t_stack *b;
    t_stack *temp;

    a = NULL;
    b = NULL;
    temp = NULL;
    if ((argc == 1) || (argc == 2 && !argv[1]))
        return 1;
    if (argc >= 2)
        argv = ft_split(argv, ' ');
    ini_stack(&a, argv);
    temp = a;
    rra(&temp);
    while (temp)
    {
        ft_printf("value is %d\n", temp->value);
        temp = temp->next;
    }
    return 0;
}