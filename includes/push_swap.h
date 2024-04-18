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

typedef struct s_stack
{
	int				value;
	int				pos;
	int				tarpos;
	int				size;
	int				first_half;
	int				set;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	int			value;
	int			tarpos;
}				t_data;

t_stack	*last_node(t_stack *stack);
int		stack_size_setpos(t_stack **stack);
void	ini_stack(t_stack **a, char **argv);

void	err_func(t_stack **stack, char **argv);
void	free_stack(t_stack **stack, char **argv);

void	pa(t_stack **a, t_stack **b, int f);
void	pb(t_stack **a, t_stack **b, int f);
void	sa(t_stack **a, int f);
void	sb(t_stack **b, int f);
void	ss(t_stack **a, t_stack **b, int f);
void	ra(t_stack **a, int f);
void	rb(t_stack **b, int f);
void	rr(t_stack **a, t_stack **b, int f);
void	rra(t_stack **a, int f);
void	rrb(t_stack **b, int f);
void	rrr(t_stack **a, t_stack **b, int f);

void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

void	set_tarpos(t_stack **stack);
void	push_chunks(t_stack **a, t_stack **b);
void	push_back(t_stack **a, t_stack **b);

int		is_sorted(t_stack **a);
int		locate_pb(t_stack **a, t_stack **b);
int		bottom_a(t_stack **a);
void	rot_push(t_stack **a, t_stack **b, int a_bot);
void	revrot_push(t_stack **a, t_stack **b, int a_bot);

#endif