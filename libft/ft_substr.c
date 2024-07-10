/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:11:16 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/17 15:02:31 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_2(char const *s, unsigned int start,
		size_t len, char *str)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = start;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len != 0 && len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (start < ft_strlen(s) && len != 0)
		str = ft_substr_2(s, start, len, str);
	return (str);
}

/*int main()
{
	char *s = ft_substr("hola", 4294967295, 0);
	printf("%ld\n", ft_strlen(s));
	return 0;
}*/
