/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:12 by kaara             #+#    #+#             */
/*   Updated: 2025/04/27 17:52:37 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void				get_colar_and_z(char *char_map, t_coordinate_data *map);
static void				atoi_to_struct(char	*char_map, t_coordinate_data *map);
static unsigned int		convert_to_rgb(char *color);

char	***make_char_map(t_coordinate	*map_size, int fd)
{
	char				*temp;
	char				***char_map;

	reset_map_index(map_size);
	char_map = (char ***)malloc(sizeof(char **) * (map_size->y + 1));
	if (char_map == NULL)
		exit(EXIT_FAILURE);
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
		{
			free(temp);
			break ;
		}
		if (*temp != '\n')
		{
			char_map[map_size->y_i] = ft_split(temp, ' ');
			map_size->y_i++;
		}
		free(temp);
	}
	return (char_map);
}

t_coordinate_data	*make_coordinate_data(char	*char_map)
{
	t_coordinate_data	*map;

	map = (t_coordinate_data *)malloc(sizeof(t_coordinate_data));
	if (map == NULL)
		exit (EXIT_FAILURE);
	atoi_to_struct(char_map, map);
	return (map);
}

static void	atoi_to_struct(char	*char_map, t_coordinate_data *map)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	if (char_map == NULL)
	{
		map->z = 0;
		map->colar = 0xFFFFFF;
		return ;
	}
	while (char_map[i] != '\0')
	{
		if (char_map[i] == ',')
			flag = true;
		i++;
	}
	if (flag)
		get_colar_and_z(char_map, map);
	else
	{
		map->z = ft_atoi(char_map);
		map->colar = 0xFFFFFF;
	}
}

static void	get_colar_and_z(char *char_map, t_coordinate_data *map)
{
	char	**temp;

	temp = ft_split(char_map, ',');
	map->z = ft_atoi(temp[0]);
	map->colar = convert_to_rgb(temp[1]);
	free(temp[0]);
	free(temp[1]);
	free(temp);
}

static unsigned int	convert_to_rgb(char *color)
{
	unsigned int	result;
	unsigned int	temp;

	result = 0;
	if (color[0] == '0' && color[1] == 'x')
		color += 2;
	while (*color)
	{
		if (ft_isdigit(*color))
			temp = *color - '0';
		else if ('A' <= *color && *color <= 'F')
			temp = *color - 'A' + 10;
		else if ('a' <= *color && *color <= 'f')
			temp = *color - 'a' + 10;
		else
			break ;
		result = (result * 16) + temp;
		color++;
	}
	return (result);
}
