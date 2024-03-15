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
    printf("value is %d | current pos is %d | next value is %d | above median %d\n", temp->value, temp->pos, temp->next->value, temp->first_half);
    temp = temp->next;
    while (temp && temp->next && temp->prev)
    {
        printf("value is %d | prev value is %d | next value is %d | pos is %d | above median %d\n", temp->value, temp->prev->value, temp->next->value, temp->pos, temp->first_half);
        temp = temp->next;
    }
    printf("value is %d | prev value is %d | current pos is %d | above median %d \n\n\n", temp->value, temp->prev->value, temp->pos, temp->first_half);
    // err_func(&a, argv, "Freed Memory");
    pb(&a, &b);
    pb(&a, &b);
    rb(&b);
    temp = b;
    printf("b value is %d\n", b->value);
    temp = b->next;
    printf("value is %d\n\n", temp->value);
    // while (temp && temp->next && temp->prev)
    // {
    //     printf("value is %d | prev value is %d | next value is %d | pos is %d | above median %d\n", temp->value, temp->prev->value, temp->next->value, temp->pos, temp->first_half);
    //     temp = temp->next;
    // }
    // err_func(&a, argv, "Freed Memory");
    // ra(&a);
    ra(&a);
    temp = a;
    printf("value is %d\n", temp->value);
    temp = temp->next;
    printf("value is %d\n", temp->value);
    // err_func(&a, argv, "Freed Memory");
    return 0;
}