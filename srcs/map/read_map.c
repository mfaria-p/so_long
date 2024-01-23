/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:04:42 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/23 20:51:23 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_checkfile(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strcmp(".ber", str[i], 4) != 0)
		ft_exit("Wrong extension of the file", EXIT_FAILURE, data);
}

void	ft_maxy(t_data *data)
{
	char	*temp;

	while (1)
	{
		temp = get_next_line(data->fd);
		if (!temp)
			break ;
		free(temp);
		data->max_y++;
	}
	if (!temp && data->max_y == 0)
		ft_exit("File is empty", EXIT_FAILURE, data);
//	free(temp);
	close(data->fd);
}

void	read_map(char *str, t_data *data)
{
	char	*temp;
	int		y;

	y = 0;
	ft_maxy(data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft("Unable to open the map file", EXIT_FAILURE, data);
	data->map = (char **)malloc(sizeof(char *) * data->max_y + 1);
	if (!data->map)
		ft_exit("Failed to allocate memory", EXIT_FAILURE, data);
	y = 0;
	while (1)
	{
		temp = get_next_line(data->fd);
		if (!temp)
			break ;
		data->map[y] = ft_strtrim(temp, "\n");
		free(temp);
		y++;
	}
	close(data->fd);
	data->map[y] = NULL;
}
