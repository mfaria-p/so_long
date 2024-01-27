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

int main(int ac, char **av)
{
	int	i;
	t_data	data;

	if (ac != 2)
		ft_exit("Wrong input.", EXIT_FAILURE, &data);
	data_init(&data);
	ft_checkfile(av[1], &data);
	read_map(av[1], &data);
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
 	i = 0;
 	if (data.map)
 	{
 		while (data.map[i])
 		{
 			free(data.map[i]);
 			i++;
 		}
 		free(data.map[i]);
 		free(data.map);
 	}
 	read_map(av[1], &data);
	game_init(&data);
	ft_exit(NULL, EXIT_SUCCESS, &data);
}
