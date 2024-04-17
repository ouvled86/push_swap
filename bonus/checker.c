/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:41:10 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/17 22:42:43 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	apply_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp("pa\n", op, 3) == 0)
		pa(a, b);
	else if (ft_strncmp("pb\n", op, 3) == 0)
		pb(a, b);
	else if (ft_strncmp("sa\n", op, 3) == 0)
		sa(a);
	else if (ft_strncmp("sb\n", op, 3) == 0)
		sb(b);
	else if (ft_strncmp("ss\n", op, 3) == 0)
		ss(a, b);
	else if (ft_strncmp("ra\n", op, 3) == 0)
		ra(a);
	else if (ft_strncmp("rb\n", op, 3) == 0)
		rb(b);
	else if (ft_strncmp("rr\n", op, 3) == 0)
		rr(a, b);
	else if (ft_strncmp("rra\n", op, 4) == 0)
		rra(a);
	else if (ft_strncmp("rrb\n", op, 4) == 0)
		rrb(b);
	else if (ft_strncmp("rrr\n", op, 4) == 0)
		rrr(a, b);
	else
		err_func(NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	a = NULL;
	b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1]) || !argv[1][0])
		return (0);
	if (argc >= 2)
		argv = ft_split(argv, ' ');
	ini_stack(&a, argv);
	if (!a)
		return (1);
	op = get_next_line(0);
	while (op)
	{
		apply_op(&a, &b, op);
		op = get_next_line(0);
	}
	if (is_sorted(&a) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
