/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:56:12 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 15:43:24 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_exit(char	*str, int i, t_data *data)
{
	int	y;

	y = 0;
	if (data->map)
	{
		while (data->map[y])
			free(data->map[y++]);
		free(data->map[y]);
		free(data->map);
	}
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_printf("Error: %s", str);
	exit(EXIT_FAILURE);
}
