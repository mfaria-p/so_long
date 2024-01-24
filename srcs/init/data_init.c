/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:28:21 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 19:31:46 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	data_init(t_data *data)
{
	data->fd = 0;
	data->map = 0;
	data->max_y = 0;
	data->max_x = 0;
	data->n_colect = 0;
	data->n_player = 0;
	data->n_exit = 0;
	data->xp = 0;
	data->yp = 0;
	data->xe = 0;
	data->ye = 0;
}
