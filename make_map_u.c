/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2024/12/25 19:56:33 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate_data	***make_coordinate_data(char	***char_map,
								t_coordinate	*map_size,
								t_window_data	*window_data,
								t_coordinate_data ***map);
static void					atoi_to_struct(char	*char_map, char	**temp,
								t_coordinate_data *map);
static int					convert_to_rgb(char *colar);

char	***make_char_map(int fd, t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	char				*temp;
	char				***char_map;

	reset_map_index(map_size);
	char_map = (char ***)malloc(sizeof(char **) * (map_size->y + 1));
	if (char_map == NULL)
		free_map(1, map_size, window_data, map);
	while (map_size->y_i < map_size->y)
	{
		temp = get_next_line(fd);
		char_map[map_size->y_i] = ft_split(temp, ' ');
		map_size->y_i++;
		free(temp);
		temp = NULL;
	}
	return (char_map);
}

t_coordinate_data	***make_map(t_coordinate	*map_size,
							t_window_data	*window_data,
							char ***char_map, t_coordinate_data ***map)
{
	reset_map_index(map_size);
	map = (t_coordinate_data ***)malloc
		(sizeof(t_coordinate_data **) * (map_size->y));
	if (map == NULL)
		free_map(1, map_size, window_data, map);
	while (map_size->y_i < map_size->y)
	{
		map[map_size->y_i] = (t_coordinate_data **)malloc
			(sizeof(t_coordinate_data *) * (map_size->x));
		if (map[map_size->y_i] == NULL)
			free_map(1, map_size, window_data, map);
		while (map_size->x_i < map_size->x)
		{
			map = make_coordinate_data(char_map, map_size, window_data, map);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (map);
}

static t_coordinate_data	***make_coordinate_data(char	***char_map,
						t_coordinate	*map_size,
						t_window_data	*window_data, t_coordinate_data ***map)
{
	char				**temp;

	temp = NULL;
	map[map_size->y_i][map_size->x_i]
		= (t_coordinate_data *)malloc(sizeof(t_coordinate_data));
	if (map[map_size->y_i][map_size->x_i] == NULL)
		free_map(1, map_size, window_data, map);
	atoi_to_struct(char_map[map_size->y_i][map_size->x_i],
		temp, map[map_size->y_i][map_size->x_i]);
	return (map);
}

static void	atoi_to_struct(char	*char_map, char	**temp, t_coordinate_data *map)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	while (char_map[i] != '\0')
	{
		if (char_map[i] == ',')
			flag = true;
		i++;
	}
	if (flag)
	{
		temp = ft_split(char_map, ',');
		map->z = ft_atoi(temp[0]);
		map->colar = convert_to_rgb(temp[1]);
		free(temp[0]);
		free(temp[1]);
		free(temp);
	}
	else
	{
		map->z = ft_atoi(char_map);
		map->colar = 0xFFFFFFFF;
	}
}

static int	convert_to_rgb(char *colar)
{
	int	result;
	int	temp;

	result = 0;
	if ((*colar == '0' && *(colar + 1) == 'x'))
		colar += 2;
	while (*colar)
	{
		if (ft_isdigit(*colar))
			temp = *colar - '0';
		else if ('A' <= *colar && *colar <= 'F')
			temp = *colar - 'A' + 10;
		result = (result * 16) + temp;
		colar++;
	}
	return (result);
}

void	free_char_map(t_coordinate *map_size, char ***char_map)
{
	reset_map_index(map_size);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x)
		{
			free(char_map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		free(char_map[map_size->y_i]);
		map_size->y_i++;
		map_size->x_i = 0;
	}
	free(char_map);
}
