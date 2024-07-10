/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:41:07 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/10 09:41:10 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < l1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		str[i + l1] = s2[i];
		i++;
	}
	str[l1 + l2] = '\0';
	return (str);
}

/*int main()
{
	printf("%s\n", ft_strjoin("ok,", " funziona"));
	return 0;
}*/
