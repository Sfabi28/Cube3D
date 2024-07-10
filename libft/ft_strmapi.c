/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:33:47 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/11 11:33:48 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char    ft_prova(unsigned int i, char c)
{
    return (c + i);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	unsigned int	t;

	t = ft_strlen(s);
	res = (char *) malloc((t + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*int main()
{
    printf("%s\n", ft_strmapi("0000", ft_prova));
    return 0;
}*/
