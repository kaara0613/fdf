/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2024/12/30 21:35:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**allocation_xpm_data(int nums_colar_def,
				t_window_data	*window_data);

char	**make_xpm_data(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data	***map)
{
	int		nums_colar_def;
	char	**xpm_data;

	nums_colar_def = count_nums_colar_def(map_size, map);
	xpm_data = allocation_xpm_data(nums_colar_def, window_data);
}

static char	**allocation_xpm_data(int nums_colar_def,
				t_window_data	*window_data)
{
	char	**xpm_data;

	xpm_data = (char **)malloc
		(sizeof(char *) * window_data->window_size_y + nums_colar_def + 1);
}

static int	*count_nums_colar_def(t_coordinate	*map_size,
				t_coordinate_data	***map)
{
	int *colar_list;

}
