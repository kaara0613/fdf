/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:10:31 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 19:11:19 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_window_data		*window_data = NULL;
	// t_coordinate		*max;
	// t_coordinate_data	**map;

	// map = make_map(fd, max);

	make_mlx_window(window_data);
	render_map(window_data);
	control_mlx_window(window_data);
	return (0);
}
