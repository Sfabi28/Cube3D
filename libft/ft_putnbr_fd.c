/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:46:13 by stescaro          #+#    #+#             */
/*   Updated: 2023/10/11 12:46:15 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < -9 || n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	if (n < 0)
	{
		if (n >= -9)
		{
			ft_putchar_fd('-', fd);
		}
		ft_putchar_fd('0' - (n % 10), fd);
	}
	else
	{
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

/*int main()
{
	ft_putnbr_fd(-23123, 1);
	return 0;
}*/
