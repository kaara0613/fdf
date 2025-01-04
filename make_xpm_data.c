/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2025/01/04 18:21:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**allocation_xpm_data(unsigned int *colar_list,
				t_window_data	*window_data);
static char	*store_xpm_header(unsigned int	*colar_list,
				t_window_data	*window_data);

char	**make_xpm_data(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data	***map)
{
	unsigned int	*colar_list;
	char			**xpm_data;

	colar_list = count_nums_colar_def(map_size, map);
	xpm_data = allocation_xpm_data(colar_list, window_data);
	xpm_data[0] = store_xpm_header(colar_list, window_data);
	xpm_data = set_background_pixel(xpm_data, window_data);
	xpm_data = store_xpm_colar_def(colar_list, xpm_data);
}

static char	**allocation_xpm_data(unsigned int *colar_list,
				t_window_data	*window_data)
{
	int			background_pixel;
	static char	**xpm_data;

	background_pixel = 1;
	xpm_data = (char **)malloc(sizeof(char *) * window_data->window_size_y
			+ (colar_list[0] + background_pixel) + 1);
	if (xpm_data == NULL)
		exit (EXIT_FAILURE);
	return (xpm_data);
}

static char	*store_xpm_header(unsigned int	*colar_list,
				t_window_data	*window_data)
{
	int		arr[5];
	char	*xpm_data;

	arr[0] = 4;
	arr[1] = window_data->window_size_x;
	arr[2] = window_data->window_size_y;
	arr[3] = colar_list[0];
	arr[4] = intlen(arr[3]);
	xpm_data = int_array_to_string(arr);
	return (xpm_data);
}

static	char	**store_xpm_colar_def(unsigned int *colar_list, char **xpm_data)
{
	ssize_t	i;

	i = 0;
	while (i <= colar_list[0])
	{
		xpm_data[i + 1] = store_colar_def(i, colar_list[i + 1]);
		i++;
	}
	return (xpm_data);
}

static char	set_background_pixel(unsigned int *colar_list,
				char **xpm_data, t_window_data	*window_data)
{
	int		x_i;
	int		y_i;
	int		colar_def_len;
	char	tmp[9];

	x_i = 0;
	y_i = colar_list[0] + 1;
	colar_def_len = intlen(colar_list[0]);
	tmp[9] = "  c None";
	xpm_data[y_i] = (char *)malloc(sizeof(char) * 9);
	if (xpm_data[y_i] == NULL)
		return (NULL);
	ft_memcpy(xpm_data[y_i], tmp, sizeof(char) * 9);
	while (y_i <= window_data->window_size_y)
	{
		xpm_data[y_i] = (char *)malloc
			(sizeof(char) * window_data->window_size_x * colar_def_len);
		if (xpm_data[y_i] == NULL)
			return (NULL);
		while (x_i < window_data->window_size_x * colar_def_len)
			//find
	}
	return (xpm_data);
}

int	find_colar_key_line(int colar_def_len, unsigned int colar, char **xpm_data)
{
	int		colar_key_line;


	return (colar_key_line);
}
