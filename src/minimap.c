/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:29:10 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 16:15:05 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(t_data *data, char *mn)
{
	char	*tmp;

	tmp = ft_strnstr(mn, ".cub", ft_strlen(mn));
	if (!tmp && ft_perror("Error\nInvalid file extension"))
		return (ft_closegame(data));
	return (0);
}

void	*find_img_ptr(t_imgs *img, char c)
{
	if (c == 0)
		return (img->empty);
	else if (c == '1' || c == 'i' || c == 'I')
		return (img->wall);
	else if (c == '0')
		return (img->floor);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (img->player);
	else if (c == 'D')
		return (img->door);
	else if (c == 'd')
		return (img->o_door);
	else if (c == 'w')
		return (img->w_wall);
	else if (c == 'e')
		return (img->e_wall);
	else if (c == 'n')
		return (img->n_wall);
	else if (c == 's')
		return (img->s_wall);
	else if (c == 'A' || c == 'B' || c == 'C' || c == 'F')
		return (img->door_closed);
	return (NULL);
}

static	void	*find_mm_texture(t_imgs *img, t_map *map, short x, short y)
{
	if (map->height <= y || map->lenght <= x || x < 0 || y < 0
		|| (short)ft_strlen(map->map[y]) <= x || !map->map[y][x]
		|| map->map[y][x] == ' ')
		return (img->empty);
	else if (map->map[y][x] == '1' || map->map[y][x] == 'I'
		|| map->map[y][x] == 'i')
		return (img->wall);
	else if (map->map[y][x] == 'd')
		return (img->o_door);
	else if (map->map[y][x] == 'D')
		return (img->door);
	else if (map->map[y][x] == '0')
		return (img->floor);
	else if (ft_strchr("NSWE", map->map[y][x]))
		return (img->player);
	return (img->empty);
}

void	display_minimap(t_data *data, t_imgs *img)
{
	short	start_x;
	short	start_y;
	short	x;
	short	y;
	void	*img_ptr;

	start_x = ((short)data->position->x - (short)(X_PIXEL / 128));
	start_y = ((short)data->position->y - (short)(X_PIXEL * 9 / 2048));
	y = start_y;
	while (y < start_y + X_PIXEL * 9 / 1024 + 1)
	{
		x = start_x;
		while (x < start_x + X_PIXEL / 64 + 1)
		{
			img_ptr = find_mm_texture(img, data->map, x, y);
			mlx_put_image_to_window(data->window->mlx, data->window->win,
				img_ptr, X_PIXEL * 4 / 5 + (x - start_x) * 10,
				X_PIXEL * 9 / 20 + (y - start_y) * 10);
			x++;
		}
		y++;
	}
}
