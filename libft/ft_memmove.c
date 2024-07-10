/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:54:43 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/10 08:54:53 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*src;
	char	*dest;
	size_t	i;

	src = (char *)str2;
	dest = (char *)str1;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest >= src && n != 0)
		while (n-- > 0)
			dest[n] = src[n];
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (str1);
}

/*#include <string.h>

int main()
{
   char buffer[]= "hello";
   char str[] = "ciaooo";
   char *test = ft_memmove(buffer, str, 6);
   char *test2 = memmove(buffer, str, 6);
   
   printf("%s\n", test2);
   printf("%s\n", test);
   
   return 0;
}*/
