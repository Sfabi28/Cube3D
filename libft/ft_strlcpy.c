/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:06:55 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/10 11:06:57 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0 || !dest || !src)
	{
		return (ft_strlen(src));
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (ft_strlen(src));
}

/*int main()
{
	char	buffer[80];
	printf("%ld\n", ft_strlcpy(buffer, "secondo", 0));
	printf("%ld\n", ft_strlcpy(buffer, "secondo", 40));
	printf("%ld\n", ft_strlcpy(buffer, "secondo", 5));
	return 0;
}*/
