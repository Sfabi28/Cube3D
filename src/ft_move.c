/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfabi <sfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:53:44 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 11:55:08 by sfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	ft_move(t_data **dt, t_position **pos, double sin, double cos)
{
	double	x;
	double	y;
	int		arr[3];

	x = (*pos)->x + cos * (0.05 / pow((1600.0 / X_PIXEL), 2) + (*dt)->cmds->sp);
	y = (*pos)->y - sin * (0.05 / pow((1600.0 / X_PIXEL), 2) + (*dt)->cmds->sp);
	arr[0] = (int)(*pos)->x;
	arr[1] = (int)(*pos)->y;
	arr[2] = 0;
	if (ft_strchr("1D", (*dt)->map->map[(int)(y - (sin > 0) * 0.1
				+ (sin <= 0) * 0.1)][(int)x]))
		arr[2]++;
	if (ft_strchr("1D", (*dt)->map->map[(int)y][(int)(x
			+ (cos > 0) * 0.1 - (cos < 0) * 0.1)]))
		arr[2] += 2;
	if (arr[2] == 0 || arr[2] == 2)
		(*pos)->y = y;
	if (arr[2] == 0 || arr[2] == 1)
		(*pos)->x = x;
	if ((int)x != arr[0] || (int)y != arr[1])
	{
		(*dt)->map->map[arr[1]][arr[0]] = (*pos)->tile;
		(*pos)->tile = (*dt)->map->map[(int)y][(int)x];
		(*dt)->map->map[(int)y][(int)x] = 'N';
	}
}

static	void	to_up_or_to_low(t_data **data, int x, int y)
{
	t_map	**map;

	map = &(*data)->map;
	if ((*map)->map[y][x] == 'D')
		(*map)->map[y][x] = 'd';
	else if ((*map)->map[y][x] == 'd')
		(*map)->map[y][x] = 'D';
}

static	void	open_door(t_position *pos, t_data **data)
{
	double	ag;
	char	**tmp;
	int		x;
	int		y;

	ag = pos->angle;
	tmp = (*data)->map->map;
	x = (int)pos->x;
	y = (int)pos->y;
	if (ft_strchr("Dd", tmp[y + 1][x])
		&& ag > 1.25 * M_PI && ag <= 1.75 * M_PI)
		to_up_or_to_low(data, x, y + 1);
	else if (ft_strchr("Dd", tmp[y - 1][x])
		&& ag > 0.25 * M_PI && ag <= 0.75 * M_PI)
		to_up_or_to_low(data, x, y - 1);
	else if (ft_strchr("Dd", tmp[y][x + 1])
		&& (ag <= 0.25 * M_PI || ag > 1.75 * M_PI))
		to_up_or_to_low(data, x + 1, y);
	else if (ft_strchr("Dd", tmp[y][x - 1])
		&& ag > 0.75 * M_PI && ag <= 1.25 * M_PI)
		to_up_or_to_low(data, x - 1, y);
}

static	short	ft_rotate(t_cmds *cmds, t_position **pos, t_data **data)
{
	(*pos)->angle += cmds->rotate * 0.1 / pow((1600.0 / X_PIXEL), 2);
	if ((*pos)->angle > 2 * M_PI)
		(*pos)->angle -= 2 * M_PI;
	if ((*pos)->angle < 0)
		(*pos)->angle += 2 * M_PI;
	if (cmds->open)
		open_door(*pos, data);
	if (cmds->move_x || cmds->move_y)
		return (0);
	return (1);
}

void	handle_cmds(t_cmds *cmds, t_data **data, t_position **pos)
{
	double	angle;

	if (ft_rotate(cmds, pos, data))
		return ;
	if (cmds->move_y == 1 && cmds->move_x == 0)
		angle = (*pos)->angle;
	else if (cmds->move_y == -1 && cmds->move_x == 0)
		angle = (*pos)->angle + M_PI;
	else if (cmds->move_x == 1 && cmds->move_y == 0)
		angle = (*pos)->angle - M_PI * 0.5;
	else if (cmds->move_x == -1 && cmds->move_y == 0)
		angle = (*pos)->angle + M_PI * 0.5;
	else if (cmds->move_x == 1 && cmds->move_y == 1)
		angle = (*pos)->angle - M_PI * 0.25;
	else if (cmds->move_x == -1 && cmds->move_y == 1)
		angle = (*pos)->angle + M_PI * 0.25;
	else if (cmds->move_x == 1 && cmds->move_y == -1)
		angle = (*pos)->angle - M_PI * 0.75;
	else
		angle = (*pos)->angle + M_PI * 0.75;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	ft_move(data, pos, sin(angle), cos(angle));
}
