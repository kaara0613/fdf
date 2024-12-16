/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:45:39 by kaara             #+#    #+#             */
/*   Updated: 2024/12/16 15:03:28 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int main(int argc, char **argv)
// {
// 	t_coordinate_data	**map;

// 	if (argc <= 1)
// 		return (0);
// 	map = fdf_to_map(argv);
// 	if (map == NULL)
// 		return (0);
// 	for (int y = 0; map[y] != NULL; y++)
// 	{
// 		for (int x = 0; map[y][x] != NULL; x++)
// 		{
// 			printf("%d", map[y][x].z);
// 			if (map[y][x].colar)
// 				printf("%d", map[y][x].colar);
// 		}
// 	}
// 	return (0);
// }

int main(int argc, char **argv)
{
	t_coordinate *map_size;

	if (argc <= 1)
		return (0);
	map_size = map_check(argv[1]);
	printf("x = %d\ny = %d", map_size->x, map_size->y);
	return (0);
}
