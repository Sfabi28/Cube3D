/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:18:13 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 14:35:25 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int	set_imgs(void *mlx, t_texture *txtr, t_data *data, t_imgs **imgs)
{
	int		i;
	t_imgs	*img;

	i = 64;
	img = *imgs;
	img->n_wall = mlx_xpm_file_to_image(mlx, txtr->no, &i, &i);
	if (!img->n_wall && ft_perror("Error\nWrong Northern wall's path"))
		return (free_imgs(*imgs, mlx), free(*imgs), ft_closegame(data));
	img->s_wall = mlx_xpm_file_to_image(mlx, txtr->so, &i, &i);
	if (!img->s_wall && ft_perror("Error\nWrong Southern wall's path"))
		return (free_imgs(*imgs, mlx), free(*imgs), ft_closegame(data));
	img->w_wall = mlx_xpm_file_to_image(mlx, txtr->we, &i, &i);
	if (!img->w_wall && ft_perror("Error\nWrong Western wall's path"))
		return (free_imgs(*imgs, mlx), free(*imgs), ft_closegame(data));
	img->e_wall = mlx_xpm_file_to_image(mlx, txtr->ea, &i, &i);
	if (!img->e_wall && ft_perror("Error\nWrong Eastern wall's path"))
		return (free_imgs(*imgs, mlx), free(*imgs), ft_closegame(data));
	img->door_closed = mlx_xpm_file_to_image(mlx,
			"imgs/door_closed.xpm", &i, &i);
	if (!img->door_closed && ft_perror("Error\nDoor's images alloc. failed"))
		return (free_imgs(*imgs, mlx), ft_closegame(data));
	return (0);
}

static	t_imgs	*set_img(void *mlx, t_texture *texture, t_data *data, int i)
{
	t_imgs	*img;
	int		j;

	img = ft_calloc(sizeof(t_imgs), 1);
	if (!img)
		return (perror("Error\nimg allocation failed"),
			free_imgs(img, mlx), free(img), ft_closegame(data), NULL);
	img->wall = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &i, &i);
	img->floor = mlx_xpm_file_to_image(mlx, "imgs/floor.xpm", &i, &i);
	img->player = mlx_xpm_file_to_image(mlx, "imgs/player.xpm", &i, &i);
	img->door = mlx_xpm_file_to_image(mlx, "imgs/door.xpm", &i, &i);
	img->o_door = mlx_xpm_file_to_image(mlx, "imgs/open_door.xpm", &i, &i);
	img->empty = mlx_xpm_file_to_image(mlx, "imgs/empty.xpm", &i, &i);
	if (!img->wall || !img->floor || !img->player || !img->door
		|| !img->empty || !img->o_door)
		return (perror("Error\nMinimap's images allocation failed"),
			free_imgs(img, mlx), free(img), ft_closegame(data), NULL);
	i = 100;
	j = 450;
	img->hand = mlx_xpm_file_to_image(mlx, "imgs/hand.xpm", &i, &j);
	if (!img->hand)
		return (perror("Error\nHand's image allocation failed"),
			free_imgs(img, mlx), free(img), ft_closegame(data), NULL);
	set_imgs(mlx, texture, data, &img);
	return (img);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (perror("Error\nWrong number of arguments"), 1);
	if (X_PIXEL < 420)
		return (perror("Error\nResolution too low"), 1);
	data = ft_calloc(sizeof(t_data), 1);
	if (check_map(argv[1], &(data->texture), &(data->map), &data))
		return (ft_freedata(data));
	data->window = ft_calloc(sizeof(t_window), 1);
	data->window->mlx = mlx_init();
	if (!data->window->mlx)
		return (perror("Error\nmlx_init failed"), ft_freedata(data));
	data->window->win = mlx_new_window(data->window->mlx, X_PIXEL,
			X_PIXEL * 9 / 16, "cub3D");
	if (!data->window->win)
		return (perror("Error\nmlx_new_window failed"), ft_freedata(data));
	data->imgs = set_img(data->window->mlx, data->texture, data, 5);
	data->cmds = ft_calloc(sizeof(t_cmds), 1);
	cub3d(data);
	return (0);
}
