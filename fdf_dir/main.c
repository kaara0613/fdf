/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 13:58:59 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int fd)
{
	t_window_data		*window_data;
	t_coordinate		*max;
	t_coordinate_data	**map;

	// map = make_map(fd, max);

	make_mlx_window(window_data);
	render_map();
	control_mlx_window(window_data);
}
