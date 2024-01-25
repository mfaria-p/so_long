/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:08:48 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/25 20:24:26 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int main(void)
{
	int	i;
	t_data	data;

	data_init(&data);
	ft_checkfile("maps/invalid/just_a_line.ber",	&data);
	read_map("maps/invalid/just_a_line.ber", &data);
	i = 0;
	while (data.map[i])
	{
		ft_printf("%s\n",data.map[i]);
		i++;
	}
	ft_mapformat(&data);
	ft_nchar(&data);
	valid_chars(&data);
 	char_coord(&data);
 	map_flood(&data);
	game_init(&data);
	ft_exit(NULL, EXIT_SUCCESS, &data);
}
