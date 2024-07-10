/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:59:22 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 12:31:10 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	put_i_img(t_data *data, void *img, short y_pxl, short i)
{
	unsigned short	dx;
	unsigned short	sx;

	dx = i % (y_pxl / 5);
	sx = (y_pxl / 5) - dx;
	mlx_put_image_to_window(data->window->mlx, data->window->win, img,
		X_PIXEL / 3 - 50, y_pxl - sx);
	mlx_put_image_to_window(data->window->mlx, data->window->win, img,
		(2 * X_PIXEL) / 3 - 50, y_pxl - dx);
}

static	void	change_sign(short i, short *sign, short move_y, short y_max)
{
	if (move_y > 0)
	{
		if (i + *sign * 10 >= y_max || i + *sign * 10 < 0)
			*sign *= -1;
	}
	else if (move_y < 0)
	{
		if (i - *sign * 10 >= y_max || i - *sign * 10 < 0)
			*sign *= -1;
	}
}

void	animation(t_data *data, t_cmds *cmds, short open)
{
	static short	i = 0;
	static short	sign = 1;

	if (open)
	{
		i = 0;
		mlx_put_image_to_window(data->window->mlx, data->window->win,
			data->imgs->hand, (2 * X_PIXEL) / 3 - 50, X_PIXEL * 9 / 32);
		return ;
	}
	change_sign(i, &sign, cmds->move_y, X_PIXEL * 9 / 80);
	if (cmds->move_y > 0)
		i += sign * 10;
	else if (cmds->move_y < 0)
		i -= sign * 10;
	put_i_img(data, data->imgs->hand, X_PIXEL * 9 / 16, i);
}
