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

    a = NULL;
    b = NULL;
    if ((argc == 1) || (argc == 2 && !argv[1]))
        return 1;
    if (argc >= 2)
        argv = ft_split(argv, ' ');
    ini_stack(&a, argv);
    b = a;
    printf("value is %d | current pos is %d | next value is %d | above median %d\n", b->value, b->pos, b->next->value, b->first_half);
    b = b->next;
    while (b && b->next && b->prev)
    {
        printf("value is %d | prev value is %d | next value is %d | pos is %d | above median %d\n", b->value, b->prev->value, b->next->value, b->pos, b->first_half);
        b = b->next;
    }
    printf("value is %d | prev value is %d | current pos is %d | above median %d \n", b->value, b->prev->value, b->pos, b->first_half);
    // err_func(&a, argv, "Freed Memory");
    return 0;
}