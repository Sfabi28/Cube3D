/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:28:37 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/05 11:59:01 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_pixel_color(void *img, int x, int y)
{
	int	*data;
	int	bits_per_pixel;
	int	l_length;
	int	endian;

	data = (int *)mlx_get_data_addr(img, &bits_per_pixel, &l_length, &endian);
	return (data[y * l_length / 4 + x]);
}

static	int	get_wall_color(short h, t_range *rg, t_data *data)
{
	void	*img;
	double	x_mm;
	double	y_mm;
	double	wall_size;
	double	y;

	wall_size = rg->wall_end - rg->wall_start;
	y = h - rg->wall_start;
	if (rg->tile == 'n' || rg->tile == 'F')
		x_mm = rg->x - (int)rg->x;
	else if (rg->tile == 's' || rg->tile == 'B')
		x_mm = 1 - (rg->x - (int)rg->x);
	else if (rg->tile == 'e' || rg->tile == 'A')
		x_mm = rg->y - (int)rg->y;
	else
		x_mm = 1 - (rg->y - (int)rg->y);
	y_mm = y / wall_size;
	img = find_img_ptr(data->imgs, rg->tile);
	return (get_pixel_color(img, (int)(x_mm * 64), (int)(y_mm * 64)));
}

static	unsigned int	find_color(short y, t_range *rg, t_data *data)
{
	if (y < rg->wall_start)
		return (data->texture->ceiling);
	else if (y > rg->wall_end)
		return (data->texture->floor);
	else
		return (get_wall_color(y, rg, data));
}

static	void	color_img_pixel(t_data *d, t_img **img, t_range *rg, int y_pxl)
{
	short				x;
	short				y;
	unsigned int		color;
	char				*pixel;

	x = 0;
	while (x < X_PIXEL)
	{
		y = 0;
		while (y < y_pxl)
		{
			color = find_color(y, rg, d);
			pixel = (*img)->data + ((y) * (*img)->size_line
					+ (X_PIXEL - 1 - x) * ((*img)->bpp / 8));
			*(int *)pixel = color;
			y++;
		}
		rg = rg->next;
		x++;
	}
}

t_img	*render_new_img(t_data *data, t_range *range, int x_pxl, int y_pxl)
{
	t_img	*img;

	img = ft_calloc(sizeof(t_img), 1);
	if (!img)
		return (perror("Error\nImage allocation failed"),
			range_lst_clear(&range), ft_closegame(data), NULL);
	img->image = mlx_new_image(data->window->mlx, x_pxl, y_pxl);
	if (!img->image)
		return (perror("Error\nmlx_new_image failed"), free(img),
			range_lst_clear(&range), ft_closegame(data), NULL);
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->size_line,
			&img->format);
	if (!img->data)
		return (perror("Error\nmlx_get_data_addr failed"), free(img),
			range_lst_clear(&range), ft_closegame(data), NULL);
	color_img_pixel(data, &img, range, y_pxl);
	return (img);
}
