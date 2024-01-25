/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaria-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:04:42 by mfaria-p          #+#    #+#             */
/*   Updated: 2024/01/24 20:28:27 by mfaria-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_checkfile(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (ft_strncmp(".ber", &str[i], 4) != 0)
		ft_exit("Wrong extension of the file", EXIT_FAILURE, data);
	data->fd = open(str, O_RDONLY, 0444);
	if (data->fd == -1)
		ft_exit("Unable to open the map file", EXIT_FAILURE, data);
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
	free(temp);
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
		ft_exit("Unable to open the map file", EXIT_FAILURE, data);
	data->map = (char **)malloc(sizeof(char *) * (data->max_y + 1));
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

void	char_coord(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->xp = j;
				data->yp = i;
			}
			else if (data->map[i][j] == 'E')
			{
				data->xe = j;
				data->ye = i;
			}
			j++;
		}
		i++;
	}
}

/*int main(void)
{
	int	i;
	t_data	data;

	data_init(&data);
	ft_checkfile("../../maps/invalid/invalid_char.ber",	&data);
	read_map("../../maps/invalid/invalid_char.ber", &data);
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
	ft_exit(NULL, EXIT_SUCCESS, &data);
}*/
