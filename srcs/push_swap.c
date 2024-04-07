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

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_stack *temp;

    a = NULL;
    b = NULL;
    if ((argc == 1) || (argc == 2 && !argv[1]))
        return 1;
    if (argc >= 2)
        argv = ft_split(argv, ' ');
    ini_stack(&a, argv);
    if (is_sorted(&a))
        exit(0);
    set_tarpos(&a);
    push_chunks(&a, &b);
    lil_sort(&a);
    push_back2(&a, &b);
    temp = a;
    while (temp)
    {
        ft_printf("value is %d, target pos is %d, size is %d\n", temp->value, temp->tarpos, temp->size);
        temp = temp->next;
    }
    // push_back(&a, &b);
    return 0;
}
