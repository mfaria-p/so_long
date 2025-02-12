/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <mfaria-p@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:28 by mfaria-p          #+#    #+#             */
/*   Updated: 2025/02/12 17:55:28 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
#include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 128
#define WIN_SIZE_H 532
#define WIN_SIZE_V 229

typedef struct s_data
{
	int		fd;
	char	**map;
	int		max_y;
	int		max_x;
	int		n_colect;
	int		n_player;
	int		n_exit;
	int		xp;
	int		yp;
	int		xe;
	int		ye;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*cimg;
	void	*eimg;
	void	*fimg;
	void	*pimg;
	void	*wimg;
	int		size;
	int		moves;
}	t_data;

void	ft_checkfile(char *str, t_data *data);
void	ft_maxy(t_data *data);
void	read_map(char *str, t_data *data);
void	ft_exit(char	*str, int i, t_data *data);
void	ft_mapformat(t_data *data);
void	ft_nchar(t_data *data);
void	data_init(t_data *data);
void	valid_chars(t_data *data);
void	char_coord(t_data *data);
void	map_flood(t_data *data);
char	**ft_flood(t_data *data, int yp, int xp, int *ne);
void	game_init(t_data *data);
void	*load_image(t_data *data, char *path);
void	set_screen(t_data *data);
void	set_image(t_data *data, int x, int y);
int		on_keypress(int keycode, t_data *data);
void	right_move(t_data *data);
void	left_move(t_data *data);
void	up_move(t_data *data);
void	down_move(t_data *data);
void	destroy_images(t_data *data);
int		end_game(t_data *data);
#endif
