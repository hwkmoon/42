/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkortbi <hkortbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:04:34 by hkortbi           #+#    #+#             */
/*   Updated: 2021/09/23 10:47:33 by hkortbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

# define M 64
# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define WHITE_PIXEL 0xFFFFFF
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLACK 0xFF000000
# define BUFFER_SIZE 1

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_vmap
{
	int	coin;
	int	exit;
	int	player;
	int	columns;
	int	rows;
	int	error;
}				t_vmap;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	*img;
	t_img	*img_wall;
	t_img	*img_floor;
	t_img	*img_player;
	t_img	*img_coin;
	t_img	*img_door;
	char	**map2d;
	t_vmap	*v_map;
	int		coin;
	int		exit;
	int		move;

}				t_data;

typedef struct s_draw
{
	int		x;
	int		y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;
}				t_draw;

int		get_next_line(int fd, char **line);
void	check_map(t_vmap *map, char **map2d);
void	draw_map(t_data *data);
void	draw_on_img(t_img *img, t_img *s_img, int startX, int startY);
void	move_player(t_data *data, char awds);
void	init_game(t_data *data);
void	free_data(t_data *data);
int		get_map2d(t_data *data, char *file);
void	first_read(t_data *data, char *file);
void	exit_all(t_data *data);
t_data	*init_data(void);
int		closer(t_data *data);
void	check_move(t_data *data, char awds, int posY, int posX);
void	move_up(t_data *data, int posY, int posX);
void	move_right(t_data *data, int posY, int posX);
void	move_left(t_data *data, int posY, int posX);
void	move_down(t_data *data, int posY, int posX);

#endif