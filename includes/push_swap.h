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
# include "libft.h"

typedef struct  s_stack
{
    int             value;
    int             pos;
    int             tarpos;
    int             size;
    int             first_half;
    int             set;
    struct s_stack  *next;
    struct s_stack  *prev;
    struct s_stack  *target;
}               t_stack;

typedef struct	s_data
{
    int	value;
	int tarpos;
}				t_data;


t_stack *last_node(t_stack *stack);
int     stack_size_setpos(t_stack **stack);
void    ini_stack(t_stack **a, char **argv);

void    err_func(t_stack **stack, char **argv, char *display_msg);

void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

void    set_tarpos(t_stack **stack);
void    push_chunks(t_stack **a, t_stack **b);
void    push_chunks2(t_stack **a, t_stack **b);
void    lil_sort(t_stack **a);
void    push_back (t_stack **a, t_stack **b);

#endif