/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/12 17:59:35 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	**fdf_to_map(int fd)
{
	char				***map_char;
	t_coordinate_data	**map;

	open(fd, O_RDONLY);
	map_char = make_map_char(fd);
	close(fd);
	map = make_map(fd);
	if (map == NULL)
		return (NULL);
	return (map);
}
