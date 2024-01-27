/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:42:36 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/26 22:47:08 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void right_move(t_data *data)
{
 	data->moves++;
 	ft_printf("Moves: %i\n", data->moves);
 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->fimg, data->xp * SIZE, data->yp * SIZE);
	data->xp++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->pimg, data->xp * SIZE, data->yp * SIZE);
	if (d->map[data->yp][data->xp] == 'C')
	{
		data->n_colect--;
		data->map[data->yp][data->xp] = '0';
	}
	if (data->xp == data->xe && data->yp == data->ye && data->n_colect == 0)
	{
		ft_printf("Yey! Game over!\n");
		ft_exit(NULL, EXIT_SUCCESS, data);
	}  
}

void left_move(t_data *data)
{
 	data->moves++;
 	ft_printf("Moves: %i\n", data->moves);
 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->fimg, data->xp * SIZE, data->yp * SIZE);
	data->xp--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->pimg, data->xp * SIZE, data->yp * SIZE);
	if (d->map[data->yp][data->xp] == 'C')
	{
		data->n_colect--;
		data->map[data->yp][data->xp] = '0';
	}
	if (data->xp == data->xe && data->yp == data->ye && data->n_colect == 0)
	{
		ft_printf("Yey! Game over!\n");
		ft_exit(NULL, EXIT_SUCCESS, data);
	}  
}

void up_move(t_data *data)
{
 	data->moves++;
 	ft_printf("Moves: %i\n", data->moves);
 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->fimg, data->xp * SIZE, data->yp * SIZE);
	data->yp--;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->pimg, data->xp * SIZE, data->yp * SIZE);
	if (d->map[data->yp][data->xp] == 'C')
	{
		data->n_colect--;
		data->map[data->yp][data->xp] = '0';
	}
	if (data->xp == data->xe && data->yp == data->ye && data->n_colect == 0)
	{
		ft_printf("Yey! Game over!\n");
		ft_exit(NULL, EXIT_SUCCESS, data);
	}  
}

void left_move(t_data *data)
{
 	data->moves++;
 	ft_printf("Moves: %i\n", data->moves);
 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->fimg, data->xp * SIZE, data->yp * SIZE);
	data->yp++;
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->pimg, data->xp * SIZE, data->yp * SIZE);
	if (d->map[data->yp][data->xp] == 'C')
	{
		data->n_colect--;
		data->map[data->yp][data->xp] = '0';
	}
	if (data->xp == data->xe && data->yp == data->ye && data->n_colect == 0)
	{
		ft_printf("Yey! Game over!\n");
		ft_exit(NULL, EXIT_SUCCESS, data);
	}  
}
