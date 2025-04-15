/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2025/01/13 16:41:58 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coordinate_data	*make_coordinate_data(char	*char_map);
static void					atoi_to_struct(char	*char_map,
								char	**temp, t_coordinate_data *map);
static unsigned int			convert_to_rgb(char *colar);
void						free_char_map(t_coordinate *map_size,
								char ***char_map);

char	***make_char_map(t_coordinate	*map_size, int fd)
{
	char				*temp;
	char				***char_map;

	reset_map_index(map_size);
	char_map = (char ***)malloc(sizeof(char **) * (map_size->y + 1));
	if (char_map == NULL)
		exit(EXIT_FAILURE);
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

t_coordinate_data	***make_map(t_coordinate	*map_size, char ***char_map)
{
	t_coordinate_data	***map;

	reset_map_index(map_size);
	map = (t_coordinate_data ***)malloc
		(sizeof(t_coordinate_data **) * (map_size->y));
	if (map == NULL)
		exit (EXIT_FAILURE);
	while (map_size->y_i < map_size->y)
	{
		map[map_size->y_i] = (t_coordinate_data **)malloc
			(sizeof(t_coordinate_data *) * (map_size->x));
		if (map[map_size->y_i] == NULL)
			exit (EXIT_FAILURE);
		while (map_size->x_i < map_size->x)
		{
			map[map_size->y_i][map_size->x_i]
				= make_coordinate_data
				(char_map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (map);
}

static t_coordinate_data	*make_coordinate_data(char	*char_map)
{
	t_coordinate_data	*map;
	char				**temp;

	temp = NULL;
	map = (t_coordinate_data *)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		exit (EXIT_FAILURE);
	atoi_to_struct(char_map, temp, map);
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
		map->colar = 0xFFFFFF;
	}
}

static unsigned int	convert_to_rgb(char *colar)
{
	unsigned int	result;
	unsigned int	temp;

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
