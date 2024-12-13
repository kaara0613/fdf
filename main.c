/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2024/12/13 13:21:44 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int fd)
{
	t_window_data		*window_data;
	t_coordinate		*max;
	t_coordinate_data	**map;

	map = make_map(fd);
	window_data = make_mlx_window();
	render_map(window_data);
	control_mlx_window(window_data);
	return (0);
}
