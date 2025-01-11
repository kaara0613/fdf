/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:44 by kaara             #+#    #+#             */
/*   Updated: 2025/01/12 00:19:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window_data	*make_mlx_window(t_window_data	*window_data)
{
	window_data->mlx_ptr = mlx_init();
	if (window_data->mlx_ptr == NULL)
		return (free(window_data), NULL);
	window_data->win_ptr
		= mlx_new_window(window_data->mlx_ptr,
			window_data->window_size_x, window_data->window_size_y, "fdf");
	if (window_data->win_ptr == NULL)
		return (free(window_data), NULL);
	mlx_clear_window(window_data->mlx_ptr, window_data->win_ptr);
	window_data->img_ptr = mlx_new_image(window_data->mlx_ptr,
			window_data->window_size_x, window_data->window_size_y);
	window_data->img_data = mlx_get_data_addr(window_data->img_ptr, &window_data->bits_per_pixel,
		&window_data->size_line, &window_data->endian);
	return (window_data);
}

void	control_mlx_window(t_window_data *window_data)
{
	mlx_put_image_to_window(window_data->mlx_ptr,
		window_data->win_ptr, window_data->img_ptr, 0, 0);
	mlx_key_hook(window_data->win_ptr, key_hook, window_data);
	mlx_loop(window_data->mlx_ptr);
}
