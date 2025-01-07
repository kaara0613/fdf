/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2025/01/07 16:21:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**store_xpm_header(char	**xpm_data, t_window_data *window_data);
static char	**set_background_pixel(char **xpm_data,
				t_window_data	*window_data);

char	**make_xpm_data(t_window_data	*window_data)
{
	int				i;
	char			**xpm_data;

	i = 0;
	xpm_data = (char **)malloc
		(sizeof(char *) * (window_data->window_size_y + 3));
	if (xpm_data == NULL)
		exit(EXIT_FAILURE);
	while (i <= window_data->window_size_y + 3)
	{
		xpm_data[i] = (char *)malloc(sizeof(char) * window_data->window_size_x);
		if (xpm_data[i] == NULL)
			exit(EXIT_FAILURE);
		i++;
	}
	return (NULL);
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
	ft_memcpy(xpm_data[0], tmp, sizeof(char) * ft_strlen(tmp));
	free(tmp);
	return (xpm_data);
}

static char	**set_background_pixel(char **xpm_data,
				t_window_data	*window_data)
{
	int		x_i;
	int		y_i;

	x_i = 0;
	y_i = 3;
	ft_memcpy(xpm_data[1], "  c None", sizeof(char) * 9);
	ft_memcpy(xpm_data[2], ". c 0xFFFFFF", sizeof(char) * 13);
	while (y_i <= window_data->window_size_y)
	{
		while (x_i < window_data->window_size_x)
			xpm_data[y_i][x_i] = ' ';
	}
	return (xpm_data);
}

void	free_xpm(char **xpm_data, t_window_data *window_data)
{
	int	i;

	i = 0;
	while (i <= window_data->window_size_y)
	{
		free(xpm_data[i]);
		i++;
	}
	free(xpm_data);
}
