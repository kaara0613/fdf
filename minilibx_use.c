/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:44 by kaara             #+#    #+#             */
/*   Updated: 2025/01/07 17:51:40 by kaara            ###   ########.fr       */
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
	return (window_data);
}

void	control_mlx_window(char **xpm_data, t_window_data *window_data)
{
	window_data->image_ptr = mlx_xpm_to_image(window_data->mlx_ptr, xpm_data,
			&window_data->window_size_x, &window_data->window_size_y);
	mlx_key_hook(window_data->win_ptr, key_hook, window_data);
	mlx_loop(window_data->mlx_ptr);
}
