/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:33:06 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/26 22:27:05 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	game_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_exit("Failed to initialise the MLX library.", EXIT_FAILURE, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->max_x * SIZE, 
			data->max_y * SIZE, "so_long");
	if (!data->win_ptr)
		ft_exit("Failed to create window.", EXIT_FAILURE, data);
	data->cimg = load_image(data, "./textures/collectible.xpm");
	data->eimg = load_image(data, "./textures/exit.xpm");
	data->fimg = load_image(data, "./textures/floor.xpm");
	data->pimg = load_image(data, "./textures/player.xpm");
	data->wimg = load_image(data, "./textures/wall.xpm");
	set_screen(data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, data);
	mlx_hook(d->mlx_win, DestroyNotify, StructureNotifyMask, &end_game, d);
	mlx_loop(data->mlx_ptr);
}

void	*load_image(t_data *data, char *path)
{
	void	*image;

	image = mlx_xpm_file_to_image(data->mlx_ptr, \
			path, &data->size, &data->size);
	if (!image)
		ft_exit("Could not convert an image.", EXIT_FAILURE, data);
	return (image);
}

void	set_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			set_image(data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	set_image(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->pimg, x * SIZE, y * SIZE);
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->eimg, x * SIZE, y * SIZE);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->cimg, x * SIZE, y * SIZE);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->fimg, x * SIZE, y * SIZE);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wimg, x * SIZE, y * SIZE);
	else
		ft_exit("Couldn't set an image.", EXIT_FAILURE, data);
}

int	on_keypress(int keycode, t_data *data)
{
	int	works;

	if (keycode == XK_Escape)
		ft_exit(NULL, EXIT_SUCCESS, data);
	else if (keycode == XK_Left && data->map[data->yp][data->xp - 1] != '1')
		left_move(data);
	else if (keycode == XK_Right && data->map[data->yp][data->xp + 1] != '1')
		right_move(data);
	else if (keycode == XK_Up && data->map[data->yp + 1][data->xp] != '1')
		up_move(data);
	else if (keycode == XK_Down && data->map[data->yp - 1][data->xp] != '1')
		down_move(data);
	return (0);
}
