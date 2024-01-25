/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:29:29 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/25 18:22:05 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	map_flood(t_data *data)
{
	int		ne;
	int		nc;

	nc = data->n_colect;
	ne = 1;
	ft_flood(data, data->yp, data->xp, &ne);
	if (data->n_colect != 0 || ne != 0)
		ft_exit("No valid path", EXIT_FAILURE, data);
	data->n_colect = nc;
}

char	**ft_flood(t_data *data, int yp, int xp, int *ne)
{
	if (data->map[yp][xp] == '1')
		return (data->map);
	else if (data->map[yp][xp] == 'X')
		return (data->map);
	else
	{
		if (data->map[yp][xp] == 'E')
			(*ne)--;
		else if (data->map[yp][xp] == 'C')
			data->n_colect--;
		data->map[yp][xp] = 'X';
		ft_flood(data, (yp + 1), xp, ne);
		ft_flood(data, (yp - 1), xp, ne);
		ft_flood(data, yp, (xp + 1), ne);
		ft_flood(data, yp, (xp - 1), ne);
		return (data->map);
	}
}
