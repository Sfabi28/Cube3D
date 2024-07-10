/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:35:00 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 14:45:56 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

short	ft_perror(char *str)
{
	perror(str);
	return (1);
}

int	count_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == '\n')
		i++;
	return (i);
}

t_position	*set_position(int i, int j, char orientation)
{
	t_position	*position;

	position = ft_calloc(sizeof(t_position), 1);
	if (!position)
		return (NULL);
	position->x = j + 0.5;
	position->y = i + 0.5;
	position->angle = 0 + M_PI * 0.5 * (orientation == 'N')
		+ M_PI * (orientation == 'W') + M_PI * 1.5 * (orientation == 'S');
	position->tile = '0';
	return (position);
}

int	skip_spaces(char *s)
{
	int		i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (i);
}

void	move_mouse(t_data **data, int x, int y)
{
	if (x > X_PIXEL - 10)
	{
		x = X_PIXEL / 2;
		mlx_mouse_move((*data)->window->mlx, (*data)->window->win, x, y);
	}
	if (x < 0 + 10)
	{
		x = X_PIXEL / 2;
		mlx_mouse_move((*data)->window->mlx, (*data)->window->win, x, y);
	}
}
