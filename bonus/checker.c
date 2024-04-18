/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:41:10 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/18 19:43:19 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	apply_op(t_stack **a, t_stack **b, char *op)
{
	if (ft_strncmp("pa\n", op, 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp("pb\n", op, 3) == 0)
		pb(a, b, 1);
	else if (ft_strncmp("sa\n", op, 3) == 0)
		sa(a, 1);
	else if (ft_strncmp("sb\n", op, 3) == 0)
		sb(b, 1);
	else if (ft_strncmp("ss\n", op, 3) == 0)
		ss(a, b, 1);
	else if (ft_strncmp("ra\n", op, 3) == 0)
		ra(a, 1);
	else if (ft_strncmp("rb\n", op, 3) == 0)
		rb(b, 1);
	else if (ft_strncmp("rr\n", op, 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp("rra\n", op, 4) == 0)
		rra(a, 1);
	else if (ft_strncmp("rrb\n", op, 4) == 0)
		rrb(b, 1);
	else if (ft_strncmp("rrr\n", op, 4) == 0)
		rrr(a, b, 1);
	else
		err_func(NULL, NULL);
	free(op);
}

void check(void)
{
	system("leaks checker");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	atexit(check);
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
	if (is_sorted(&a) == 0 && !b)
		ft_printf("OK\n");
	else if ((is_sorted(&a) == 1 || b))
		ft_printf("KO\n");
	free_checker_mem(&a, &b, argv);
	return (0);
}
