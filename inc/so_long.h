/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:25:28 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/23 20:53:17 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
#define SOLONG_H

# include "../libraries/minilibx-linux/mlx"
# include "../libraries/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fd;
	char	**map;
	int		max_y;
	int		max_x;
	int		n_colect;
	int		n_player;
	int		n_exit;
}	tdata

void	ft_checkfile(char *str, t_data *data);
void	ft_maxy(t_data *data);
void	read_map(char *str, t_data *data);

#endif
