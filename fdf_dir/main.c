/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2024/12/10 16:01:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int fd)
{
	int				**map;
	t_coordinate	*max;

	map = make_map(fd, max);
	for (int y = 0; y <= max->y; y++)
	{
		for (int x = 0; x <= max->x; x++)
			printf("%d,", map[y][x]);
		printf("\n");
	}
}
