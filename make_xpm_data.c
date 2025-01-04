/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2025/01/04 23:17:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**store_xpm_header(char	**xpm_data, t_window_data *window_data);
static char	set_background_pixel(char **xpm_data, t_window_data	*window_data);

char	**make_xpm_data(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data	***map)
{
	int				y_i;
	char			**xpm_data;

	y_i = 0;
	xpm_data = (char **)malloc
		(sizeof(char *) * window_data->window_size_y + 3);
	if (xpm_data == NULL)
		return (NULL);
	while (y_i <= window_data->window_size_y + 3)
	{
		xpm_data[y_i] = (char *)malloc
			(sizeof(char) * window_data->window_size_x);
		if (xpm_data[y_i] == NULL)
			return (NULL);
		y_i++;
	}
	xpm_data = store_xpm_header(xpm_data, window_data);
	xpm_data = set_background_pixel(xpm_data, window_data);
	return (xpm_data);
}

static char	**store_xpm_header(char	**xpm_data, t_window_data *window_data)
{
	int		arr[5];
	char	*tmp;

	arr[0] = 4;
	arr[1] = window_data->window_size_x;
	arr[2] = window_data->window_size_y;
	arr[3] = 2;
	arr[4] = 1;
	tmp = int_array_to_string(arr);
	ft_mamcpy(xpm_data[0], tmp, sizeof(char) * ft_strlen(tmp));
	free(tmp);
	return (xpm_data);
}

static char	set_background_pixel(char **xpm_data, t_window_data	*window_data)
{
	int		x_i;
	int		y_i;
	char	tmp[13];

	x_i = 0;
	y_i = 3;
	tmp[9] = "  c None";
	ft_memcpy(xpm_data[1], tmp, sizeof(char) * 9);
	tmp[9] = ". c 0xFFFFFF";
	ft_memcpy(xpm_data[2], tmp, sizeof(char) * 13);
	while (y_i <= window_data->window_size_y)
	{
		while (x_i <= window_data->window_size_x)
		{
			xpm_data[y_i][x_i] = ' ';
			x_i++;
		}
		y_i++;
	}
	return (xpm_data);
}
