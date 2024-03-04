
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

static char	*extract(char *s, char c)
{
	static int	tpos;
	// int			ressize;
	int			j;
	char		*res;

	if (s[tpos] && s[tpos] == c)
		tpos++;
	j = tpos;
	while (s[tpos] && s[tpos] != c)
		tpos++;
	res = (char *)malloc((tpos + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (tpos > j)
	{
		res[j] = s[j];
		j++;
	}
	res[j] = '\0';
	// printf("%d\n", tpos);
	return (res);
}

char	**ft_split(char **s, char c)
{
	int		j;
	int		occurances;
	char	**result;

	j = 0;
	if (!s || !*s)
		return (NULL);
	occurances = check(s, c);
	printf("%d ocs\n", occurances);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	while (j < occurances)
	{
		for (int k = 1; s[k]; k++)
		{
			result[j] = extract(s[k], c);
			if (result[j] == NULL)
				return (freemem(result));
			// printf("i is %d\nj is %d\nk is %d\n", i, j, k);
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
