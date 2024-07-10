/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stescaro <stescaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:23:17 by stescaro          #+#    #+#             */
/*   Updated: 2024/06/10 16:14:54 by stescaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef X_PIXEL
#  define X_PIXEL 1600
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>

typedef struct s_position
{
	double	x;
	double	y;
	double	angle;
	char	tile;
}	t_position;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		ceiling;
	int		floor;
}	t_texture;

typedef struct s_range
{
	short			i;
	double			range;
	double			x;
	double			y;
	double			angle;
	char			tile;
	short			wall_start;
	short			wall_end;
	struct s_range	*next;
}	t_range;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_map
{
	short	lenght;
	short	height;
	char	**map;
}	t_map;

typedef struct s_imgs
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*door;
	void	*empty;
	void	*hand;
	void	*o_door;
	void	*n_wall;
	void	*s_wall;
	void	*w_wall;
	void	*e_wall;
	void	*door_closed;
}	t_imgs;

typedef struct s_cmds
{
	short	move_x;
	short	move_y;
	float	rotate;
	short	open;
	float	sp;
}	t_cmds;

typedef struct s_data
{
	struct s_cmds		*cmds;
	struct s_map		*map;
	struct s_texture	*texture;
	struct s_position	*position;
	struct s_window		*window;
	struct s_imgs		*imgs;
}	t_data;

void			cub3d(t_data *data);
short			ft_perror(char *str);
short			check_map(char *mn, t_texture **tt, t_map **map, t_data **data);
int				ft_freedata(t_data *data);
t_position		*set_position(int i, int j, char orientation);
int				set_texture(char *map_line, t_texture **texture);
short			is_minimap(short x, short y, short x_pxl, short y_pxl);
int				get_minimap_color(short x, short y, t_data *data);
int				ft_closegame(t_data *data);
int				count_nl(char *s);
void			*raycast(t_data *data, double angle);
void			handle_cmds(t_cmds *cmds, t_data **data, t_position **pos);
t_range			*range_lstnew(t_data *data, double arr[3],
					double angle, char tile);
void			range_lstadd_back(t_range **lst, t_range *new);
void			range_lst_clear(t_range **lst);
t_img			*render_new_img(t_data *data, t_range *range,
					int x_pxl, int y_pxl);
void			*find_img_ptr(t_imgs *img, char c);
int				get_pixel_color(void *img, int x, int y);
void			display_minimap(t_data *data, t_imgs *img);
void			move_mouse(t_data **data, int x, int y);
void			animation(t_data *data, t_cmds *cmds, short open);
void			free_imgs(t_imgs *imgs, void *mlx);
int				skip_spaces(char *s);
int				check_cub(t_data *data, char *mn);

#endif