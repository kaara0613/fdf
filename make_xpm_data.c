/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2025/01/01 15:31:55 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**allocation_xpm_data(int *colar_list,
				t_window_data	*window_data);
static char	*store_xpm_header(int	*colar_list, t_window_data	*window_data);

char	**make_xpm_data(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data	***map)
{
	int		*colar_list;
	char	**xpm_data;

	colar_list = count_nums_colar_def(map_size, map);
	xpm_data = allocation_xpm_data(colar_list, window_data);
	xpm_data[0] = store_xpm_header(colar_list, window_data);
	xpm_data = store_xpm_colar_def(colar_list, xpm_data);
}

static char	**allocation_xpm_data(int *colar_list,
				t_window_data	*window_data)
{
	static char	**xpm_data;

	xpm_data = (char **)malloc
		(sizeof(char *) * window_data->window_size_y + colar_list[0] + 1);
	if (xpm_data == NULL)
		exit (EXIT_FAILURE);
	return (xpm_data);
}

static char	*store_xpm_header(int	*colar_list, t_window_data	*window_data)
{
	int	arr[4];

	arr[0] = 4;
	arr[1] = window_data->window_size_x;
	arr[2] = window_data->window_size_y;
	arr[3] = colar_list[0];
	arr[4] = 1;
	xpm_data = int_array_to_string(arr);
	return (xpm_data);
}

static	char	**store_xpm_colar_def(int *colar_list, char **xpm_data)
{
	
}