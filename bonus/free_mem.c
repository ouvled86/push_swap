/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:19 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/18 21:54:11 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_checker_mem(t_stack **a, t_stack **b, char **argv)
{
	t_stack	*temp;

	temp = NULL;
	if (*a)
	{
		temp = *a;
		while (temp)
		{
			temp = temp->next;
			free(*a);
			*a = temp;
		}
	}
	if (*b)
	{
		temp = *b;
		while (temp)
		{
			temp = temp->next;
			free(*b);
			*b = temp;
		}
	}
	if (argv && *argv)
		argv = freemem(argv);
}
