/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:50:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 19:11:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	render_map(t_coordinate_data **map)
// {


// }

void	render_map(t_window_data	*window_data)
{
	mlx_pixel_put(window_data->mlx_ptr, window_data->win_ptr, 0, 0, 0x00FF0000);
}
