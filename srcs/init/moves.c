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
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->pimg, d->xp * SIZE, d->yp * SIZE);
  
}
