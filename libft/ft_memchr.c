/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:49:56 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/09 16:49:58 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)str;
	while (n > 0)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
		n--;
	}
	return (0);
}

/*int main()
{
    const void  *str = "ABFDEFgdsgds";
    int c = 70;
    size_t  n = 6;
    char    *result;

    result = ft_memchr(str, c, n);
    printf("%s\n", result);
    return (0);
}*/
