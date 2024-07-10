/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:58:59 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/04 10:44:51 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	range_lst_clear(t_range **lst)
{
	t_range	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

void	range_lstadd_back(t_range **lst, t_range *new)
{
	t_range	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_range	*range_lstnew(t_data *data, double arr[3], double angle, char tile)
{
	t_range			*new;
	short			h;
	short			wall_h;
	static short	i = 0;

	new = ft_calloc(sizeof(t_range), 1);
	if (!new)
		return (NULL);
	new->i = i;
	new->range = arr[2];
	new->angle = angle;
	new->tile = tile;
	new->x = arr[0];
	new->y = arr[1];
	h = (int)(X_PIXEL * 9 / 16);
	wall_h = (short)(h / (arr[2] * cos(angle - data->position->angle)));
	new->wall_start = (h - wall_h) / 2;
	new->wall_end = new->wall_start + wall_h;
	new->next = NULL;
	i++;
	return (new);
}
