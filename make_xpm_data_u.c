/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_xpm_data_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:29:18 by kaara             #+#    #+#             */
/*   Updated: 2025/01/02 18:49:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//count
static bool			is_color_in_list(unsigned int	*colar_list,
						t_coordinate *map_size, t_coordinate_data	***map);
static unsigned int	*update_colar_list(unsigned int *colar_list,
						t_coordinate_data	*map);

int	*count_nums_colar_def(t_coordinate	*map_size,
				t_coordinate_data	***map)
{
	unsigned int		*colar_list;

	colar_list = (unsigned int *)malloc(sizeof(unsigned int) * 1);
	if (colar_list == NULL)
		exit(EXIT_FAILURE);
	while (map_size->y_i < map_size->y)
	{
		while (map_size->x_i < map_size->x - 1)
		{
			if (is_color_in_list(colar_list, map_size, map))
				update_colar_list(colar_list,
					map[map_size->y_i][map_size->x_i]);
			map_size->x_i++;
		}
		map_size->y_i++;
		map_size->x_i = 0;
	}
	return (colar_list);
}

static bool	is_color_in_list(unsigned int	*colar_list,
				t_coordinate	*map_size, t_coordinate_data	***map)
{
	bool	flag;
	int		i;

	if (map[map_size->y_i][map_size->x_i]->colar == 0)
		return (false);
	i = 1;
	while (i <= colar_list[0])
	{
		if (colar_list[i] == map[map_size->y_i][map_size->x_i]->colar)
		{
			flag = false;
			break ;
		}
		flag = true;
		i++;
	}
	return (flag);
}

static unsigned int	*update_colar_list(unsigned int *colar_list,
						t_coordinate_data	*map)
{
	unsigned int	*temp;

	temp = (unsigned int *)malloc(sizeof(unsigned int) * (colar_list[0] + 1));
	if (temp == NULL)
		exit (EXIT_FAILURE);
	ft_mamcpy(temp, colar_list, sizeof(unsigned int) * (colar_list[0] + 1));
	temp[0]++;
	free(colar_list);
	colar_list = NULL;
	colar_list = (unsigned int *)malloc(sizeof(unsigned int) * (temp[0] + 1));
	if (colar_list == NULL)
		exit (EXIT_FAILURE);
	ft_mamcpy(colar_list, temp, sizeof(unsigned int) * (temp[0] + 1));
	free(temp);
}
