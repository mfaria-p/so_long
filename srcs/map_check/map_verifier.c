/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:07:48 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 20:27:26 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_mapformat(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	data->max_x = (int)ft_strlen(data->map[x]);
	while (data->map[++x])
		if (data->max_x != (int)(ft_strlen(data->map[x])))
			ft_exit("The map is not retangular", EXIT_FAILURE, data);
	if (data->max_x < 3 || data->max_y < 3)
		ft_exit("Not enough width and height.", EXIT_FAILURE, data);
	x = 0;
	while (data->map[0][x] != '\0' && data->map[data->max_y - 1][x])
	{
		if (data->map[0][x] != '1' || data->map[data->max_y - 1][x] != '1')
			ft_exit("Missing walls.", EXIT_FAILURE, data);
		x++;
	}
	y = 1;
	while (data->map[y])
	{
		if (data->map[y][0] != '1' || data->map[y][data->max_x - 1] != '1')
			ft_exit("Missing walls.", EXIT_FAILURE, data);
		y++;
	}
}

void	ft_nchar(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
				data->n_player++;
			else if (data->map[i][j] == 'E')
				data->n_exit++;
			else if (data->map[i][j] == 'C')
				data->n_colect++;
			j++;
		}
		i++;
	}
	if (data->n_player != 1)
		ft_exit("Wrong number of P in the map.", EXIT_FAILURE, data);
	if (data->n_exit != 1)
		ft_exit("Wrong number of E in the map.", EXIT_FAILURE, data);
	if (data->n_colect == 0)
		ft_exit("There must be collectibles in the map.", EXIT_FAILURE, data);
}

void	valid_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] != 'P' && data->map[i][j] != 'E' 
					&& data->map[i][j] != 'C' && data->map[i][j] != '0' 
						&& data->map[i][j] != '1')
				ft_exit("Invalid characters in the map", EXIT_FAILURE, data);
			j++;
		}
		i++;
	}
}
