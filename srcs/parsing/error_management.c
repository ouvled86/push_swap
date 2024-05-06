/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 03:50:08 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/06 13:26:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	err_func(t_stack **stack, char **argv)
{
	t_stack	*temp;

	write(2, "Error\n", 6);
	temp = NULL;
	if (stack && *stack)
	{
		temp = *stack;
		while (temp)
		{
			temp = temp->next;
			free(*stack);
			*stack = temp;
		}
	}
	if (argv && *argv)
		argv = freemem(argv);
	exit (1);
}

void	free_stack(t_stack **stack, char **argv)
{
	t_stack	*temp;

	temp = NULL;
	if (stack && *stack)
	{
		temp = *stack;
		while (temp)
		{
			temp = temp->next;
			free(*stack);
			*stack = temp;
		}
	}
	if (argv && *argv)
		argv = freemem(argv);
}
