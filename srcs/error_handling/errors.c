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
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (i == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_printf("Error: %s", str);
	exit(EXIT_FAILURE);
}

void	destroy_images(t_data *data)
{
	if (data->cimg)
		mlx_destroy_image(data->mlx_ptr, data->cimg);
	if (data->eimg)
		mlx_destroy_image(data->mlx_ptr, data->eimg);
	if (data->fimg)
		mlx_destroy_image(data->mlx_ptr, data->fimg);
	if (data->pimg)
		mlx_destroy_image(data->mlx_ptr, data->pimg);
	if (data->wimg)
		mlx_destroy_image(data->mlx_ptr, data->wimg);
}

int	end_game(t_data *data)
{
	ft_exit(NULL, EXIT_SUCCESS, data);
	return (0);
}
