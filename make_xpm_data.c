/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by kaara             #+#    #+#             */
/*   Updated: 2024/12/31 16:19:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	**allocation_xpm_data(int *colar_list,
				t_window_data	*window_data);

char	**make_xpm_data(t_coordinate	*map_size,
			t_window_data	*window_data, t_coordinate_data	***map)
{
	int		*colar_list;
	char	**xpm_data;

	colar_list = count_nums_colar_def(map_size, map);
	xpm_data = allocation_xpm_data(colar_list, window_data);
}

static char	**allocation_xpm_data(int *colar_list,
				t_window_data	*window_data)
{
	char	**xpm_data;

	xpm_data = (char **)malloc
		(sizeof(char *) * window_data->window_size_y + *colar_list + 1);
	if (xpm_data == NULL)
		exit (EXIT_FAILURE);
}

static int	*count_nums_colar_def(t_coordinate	*map_size,
				t_coordinate_data	***map)
{
	int i;
	int	*colar_list;

	colar_list = NULL;
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x - 1)
		{
			while (map[map_size->y_i][map_size->x_i]->colar)
			update_colar_list(colar_list, map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (colar_list);
}

static int	*update_colar_list(int *colar_list, t_coordinate_data	*map)
{
	int	*temp;

	if (colar_list != NULL)
	{
		temp = (int *)malloc(sizeof(int) * (colar_list[0] + 1));
		if (temp == NULL)
			exit (EXIT_FAILURE);
		ft_mamcpy(temp, colar_list, sizeof(int) * (colar_list[0] + 1));
		free(colar_list);
		colar_list = NULL;
	}

}
