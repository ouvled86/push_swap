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

void	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size > 3)
	{
		set_tarpos(a);
		push_chunks(a, b);
		lil_sort(a);
		push_back(a, b);
	}
	if (size == 3)
	{
		set_tarpos(a);
		lil_sort(a);
	}
	if (size == 2)
		sa(a);
	if (size == 1)
		exit (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1]))
		return (1);
	if (argc >= 2)
		argv = ft_split(argv, ' ');
	ini_stack(&a, argv);
	if (!a)
		return (30);
	if (is_sorted(&a) == 0)
		exit(0);
	push_swap(&a, &b, a->size);
	return (0);
}
