/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:29:29 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 20:31:04 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/solong.h"

void	map_flood(t_data *data)
{
	int		ne;
	int		nc;

	nc = 0;
	ne = 1;
	ft_flood(data, data->yp, data->xp, &ne, &nc);
	if (data->n_colect != nc || ne != 0)
		ft_exit("No valid path", EXIT_FAILURE, data);
}

char	**ft_flood(t_data *data, int yp, int xp, int *ne, int *nc)
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
			(*nc)++;
		data->map[yp][xp] = 'X';
		ft_flood(data, (yp + 1), xp, ne, nc);
		ft_flood(data, (yp - 1), xp, ne, nc);
		ft_flood(data, yp, (xp + 1), ne, nc);
		ft_flood(data, yp, (xp - 1), ne, nc);
		return (data->map);
	}
}
