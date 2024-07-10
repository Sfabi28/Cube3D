/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 09:02:12 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/05 11:58:23 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	double	set_n(double angle, double x, double y)
{
	double	nx;
	double	ny;
	double	cs;
	double	sn;

	cs = cos(angle);
	sn = sin(angle);
	if (cs != 0)
		nx = fabs(((int)x - x + (cs > 0) - 0.00000000000001 * (cs < 0)) / cs);
	else
		nx = INT_MAX;
	if (sn != 0)
		ny = fabs(((int)y - y + (sn < 0) - 0.00000000000001 * (sn > 0)) / sn);
	else
		ny = INT_MAX;
	if (nx < ny)
		return (nx);
	return (ny);
}

static	char	set_tile(char c, double x, double y)
{
	if (c == '1')
	{
		if (x - (int)x < 0.000001)
			return ('e');
		else if (y - (int)y < 0.000001)
			return ('s');
		else if (x - (int)x > 0.999999)
			return ('w');
		else if (y - (int)y > 0.999999)
			return ('n');
	}
	else if (c == 'D' || c == 'I')
	{
		if (x - (int)x < 0.000001)
			return ('A');
		else if (y - (int)y < 0.000001)
			return ('B');
		else if (x - (int)x > 0.999999)
			return ('C');
		else if (y - (int)y > 0.999999)
			return ('F');
	}
	else
		return ('i');
	return ('0');
}

static	t_range	*set_range(t_data *data, double angle, char tile)
{
	double	arr[3];
	t_map	*map;

	map = data->map;
	arr[0] = data->position->x;
	arr[1] = data->position->y;
	arr[2] = 1;
	while (map->map[(int)arr[1]][(int)arr[0]] != '1'
		&& map->map[(int)arr[1]][(int)arr[0]] != 'D'
		&& map->map[(int)arr[1]][(int)arr[0]] != 'I')
	{
		arr[2] = set_n(angle, arr[0], arr[1]);
		arr[0] += arr[2] * cos(angle);
		arr[1] -= arr[2] * sin(angle);
	}
	tile = set_tile(data->map->map[(int)arr[1]][(int)arr[0]], arr[0], arr[1]);
	arr[2] = sqrt(pow(arr[0] - data->position->x, 2)
			+ pow(arr[1] - data->position->y, 2));
	return (range_lstnew(data, arr, angle, tile));
}

void	*raycast(t_data *data, double angle)
{
	t_range	*range;
	short	i;
	void	*img;

	i = -1;
	range = NULL;
	while (++i < X_PIXEL)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		else if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		range_lstadd_back(&range, set_range(data, angle, 0));
		angle += M_PI / (3 * X_PIXEL);
	}
	img = render_new_img(data, range, X_PIXEL, X_PIXEL * 9 / 16);
	range_lst_clear(&range);
	return (img);
}
