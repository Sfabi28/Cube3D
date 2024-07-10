/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:25:55 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/11 10:25:56 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_figures(int n)
{
	int	t;

	if (n == -2147483648)
		return (11);
	t = 0;
	if (n <= 0)
	{
		n = -n;
		t++;
	}
	while (n != 0)
	{
		n = n / 10;
		t++;
	}
	return (t);
}

static	int	ft_power(int nb, int power)
{
	int	i;
	int	j;

	i = 1;
	j = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	while (i < power)
	{
		j = j * nb;
		i++;
	}
	return (j);
}

static	char	*ft_itoa_2(int n, int fig, int i, char *res)
{
	if (n < 0)
	{
		res[i] = '-';
		i++;
		n = -n;
		fig--;
	}
	fig--;
	while (fig >= 0)
	{
		res[i] = 48 + (n / ft_power(10, fig)) % 10;
		i++;
		fig--;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		fig;

	fig = ft_figures(n);
	res = (char *) malloc((fig + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		res[0] = '-';
		res[1] = '2';
		res = ft_itoa_2(147483648, 9, 2, res);
		return (res);
	}
	res = ft_itoa_2(n, fig, 0, res);
	return (res);
}

/*int main()
{
	printf("%s\n", ft_itoa(0));
	return 0;
}*/
