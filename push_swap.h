/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:49:20 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/15 03:49:20 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct  s_stack
{
    int             value;
    int             pos;
    int             cost;
    int             first_half;
    struct s_stack  *next;
    struct s_stack  *prev;
    struct s_stack  *target;
}               t_stack;

void    ini_stack(t_stack **a, char **argv);
int     stack_size_setpos(t_stack **stack);
void    err_func(t_stack **stack, char **argv, char *display_msg);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);


#endif