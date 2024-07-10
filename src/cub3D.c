/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:15:06 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 12:19:03 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	ft_keyhook(int keysym, t_data **data)
{
	t_cmds	*cmds;

	if (keysym == 65307)
		ft_closegame(*data);
	cmds = (*data)->cmds;
	if (keysym == XK_w)
		cmds->move_y = 1;
	else if (keysym == XK_s)
		cmds->move_y = -1;
	else if (keysym == XK_a)
		cmds->move_x = -1;
	else if (keysym == XK_d)
		cmds->move_x = 1;
	else if (keysym == XK_Left)
		cmds->rotate = 1;
	else if (keysym == XK_Right)
		cmds->rotate = -1;
	else if (keysym == XK_Shift_L)
		cmds->sp = 0.05;
	return (0);
}

static	int	ft_keyrelease(int keysym, t_cmds **cmds)
{
	if (keysym == XK_w || keysym == XK_s)
		(*cmds)->move_y = 0;
	else if (keysym == XK_a || keysym == XK_d)
		(*cmds)->move_x = 0;
	else if (keysym == XK_Left || keysym == XK_Right)
		(*cmds)->rotate = 0;
	else if (keysym == XK_space)
		(*cmds)->open = 1;
	else if (keysym == XK_Shift_L)
		(*cmds)->sp = 0;
	return (0);
}

static	int	ft_mousehook(int x, int y, t_data **data)
{
	static int	past_x = X_PIXEL / 2;

	move_mouse(data, x, y);
	if (x == past_x)
	{
		past_x = x;
		return (0);
	}
	if (x > past_x)
		(*data)->position->angle -= 0.015 / pow((1600.0 / X_PIXEL), 2);
	else
		(*data)->position->angle += 0.015 / pow((1600.0 / X_PIXEL), 2);
	past_x = x;
	return (0);
}

static	int	ft_render(t_data **data)
{
	t_img	*img;
	short	open;

	open = (*data)->cmds->open;
	handle_cmds((*data)->cmds, data, &(*data)->position);
	(*data)->cmds->open = 0;
	img = raycast(*data, (*data)->position->angle - M_PI / 6);
	mlx_put_image_to_window((*data)->window->mlx, (*data)->window->win,
		img->image, 0, 0);
	if (BONUS)
	{
		animation(*data, (*data)->cmds, open);
		display_minimap(*data, (*data)->imgs);
	}
	mlx_destroy_image((*data)->window->mlx, img->image);
	free(img);
	return (0);
}

void	cub3d(t_data *data)
{
	mlx_hook(data->window->win, 2, 1L << 0, ft_keyhook, &data);
	if (BONUS)
		mlx_mouse_move(data->window->mlx, data->window->win,
			X_PIXEL / 2, X_PIXEL * 9 / 32);
	if (BONUS)
		mlx_hook(data->window->win, MotionNotify, PointerMotionMask,
			ft_mousehook, &data);
	mlx_key_hook(data->window->win, ft_keyrelease, &(data->cmds));
	mlx_hook(data->window->win, 17, 1L << 17, ft_closegame, data);
	mlx_loop_hook(data->window->mlx, ft_render, &data);
	mlx_loop(data->window->mlx);
}
