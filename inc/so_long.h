/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:28 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 14:57:14 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

# include "../libraries/minilibx-linux/mlx.h"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>

# define SIZE 18

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
	int	size;
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

#endif
