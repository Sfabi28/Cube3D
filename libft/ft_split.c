/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:24:49 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/11 08:24:51 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freesplit(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	count(char const *cs, char c)
{
	int	i;

	i = 0;
	while (cs[i] != c && cs[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**split2(char const *s, char c, char **str, int a)
{
	int	t;

	while (*s)
	{
		t = count(s, c);
		if (t)
		{
			str[a] = (char *)malloc((t + 1) * sizeof(char));
			if (!str[a])
			{
				ft_freesplit(str);
				return (NULL);
			}
			while (*s != c && *s != '\0')
				*str[a]++ = *s++;
			*str[a] = '\0';
			str[a] = str[a] - t;
			a++;
		}
		else
			s++;
	}
	str[a] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	t;

	t = ft_count(s, c);
	str = (char **)malloc((t + 1) * sizeof (char *));
	if (!str)
		return (NULL);
	str = split2(s, c, str, 0);
	return (str);
}

/*int main()
{
	char **res;
	char	*s=" se ";
	size_t	count;
	size_t	i=0;
	char c=' ';
	
	res = ft_split(s, c);
	count = ft_count(s, c);
	while (i < count)
	{
		printf("%s\n", res[i]);
		i++;
	}
	return 0;
}*/
