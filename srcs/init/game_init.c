/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:33:06 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/25 20:55:45 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit("Failed to initialise the MLX library.", EXIT_FAILURE, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->max_x * SIZE, data->max_y * SIZE, "so_long");
	if (!data->win_ptr)
		ft_exit("Failed to create window.", EXIT_FAILURE, data);
}
/	data->cimg = load_image(data, "textures/collectible.xpm");
//	data->eimg = load_image(data, "textures/exit.xpm");
	data->fimg = load_image(data, "textures/floor.xpm");
	data->pimg = load_image(data, "textures/player.xpm");
	data->wimg = load_image(data, "textures/wall.xpm");
	load_screen(t_data *data);

}

void	*load_image(t_data *data, char *path)
{
	image = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->size, &data->size);
	if (!image)
		ft_exit("Could not convert an image.", EXIT_FAILURE, data);
	return(image);
}

void	load_screen(t_data *data)
