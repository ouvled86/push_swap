/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/05 19:03:56 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char **str, char c)
{
	int	occurances;
	int	i;
	int	j;

	occurances = 0;
	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] >= '0' && str[j][i] <= '9')
				occurances++;
			else
				return (printf("ERROR\n"), -1);				
			while (str[j][i] >= '0' && str[j][i] <= '9')
				i++;
			if (str[j][i] == c)
				i++;
			if (!(str[j][i] >= '0' && str[j][i] <= '9') && str[j][i])
				return (printf("ERROR\n"), -1);				
		}
		j++;
	}
	return (occurances);
}

static char	**freemem(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
			free(res[i++]);
		free(res);
	}
	return (NULL);
}

static char	*extract(int *i, char *s, char c)
{
	int		ressize;
	int		tpos;
	int		j;
	char	*res;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	tpos = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	ressize = *i - tpos;
	res = (char *)malloc((ressize + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (tpos + j < *i)
	{
		res[j] = s[tpos + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split(char **s, char c)
{
	int		j;
	int		occurances;
	char	**result;
	int		i;

	j = 0;
	if (!s || !*s)
		return (NULL);
	occurances = check(s, c);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	for (int k = 1; s[k]; k++)
	{
		i = 0;
		while (j < occurances && s[k][i])
		{
			result[j] = extract(&i, s[k], c);
			if (result[j] == NULL)
				return (freemem(result));
			j++;
		}
	}
	result[occurances] = NULL;
	return (result);
}

// int main(int argc, char **argv)
// {
//     printf("%d\n", check(argv, ' '));
// }
