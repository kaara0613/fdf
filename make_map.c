/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:19 by kaara             #+#    #+#             */
/*   Updated: 2024/12/13 00:27:25 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coordinate_data	**fdf_to_map(int argc, char **argv)
{
	char				***map_char;
	t_coordinate_data	**map;

	open(argv[1], O_RDONLY);
	map_char = make_map_char();
	close(argv[1]);
	map = make_map();
	if (map == NULL)
		return (NULL);
	return (map);
}
