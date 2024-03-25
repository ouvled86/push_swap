/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/03/25 21:57:03 by ouel-bou         ###   ########.fr       */
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
			if ((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == '-')
				occurances++;
			else
				return (printf("Error\n"), -1);				
			while ((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == '-')
				i++;
			if (str[j][i] == c)
				i++;
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][i] == '-') && str[j][i])
				return (printf("Error\n"), exit(1), -1);				
		}
		j++;
	}
	return (occurances);
}

char	**freemem(char **res)
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
	while (s[*i] && s[*i] == c)
        (*i)++;
	return (res);
}

void	extract_all(int *i, int *j, int k, int o, char **s, char **r)
{
	while (*j < o && s[k][*i])
	{
		r[*j] = extract(i, s[k], ' ');
		if (r[*j] == NULL)
			r = freemem(r);
		(*j)++;
	}
}

char	**ft_split(char **s, char c)
{
	int		occurances;
	char	**result;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 1;
	if (!s || !*s)
		return (NULL);
	occurances = check(s, c);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	while (s[k])
	{
		i = 0;
		extract_all(&i, &j, k, occurances, s, result);
		k++;
	}
	result[occurances] = NULL;
	return (result);
}
