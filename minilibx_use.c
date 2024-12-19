/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:44 by kaara             #+#    #+#             */
/*   Updated: 2024/12/19 13:18:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window_data	*make_mlx_window(int window_size)
{
	t_window_data		*window_data;

	window_data = malloc(sizeof(t_window_data));
	window_data->mlx_ptr = mlx_init();
	if (window_data->mlx_ptr == NULL)
		return (free(window_data), NULL);
	window_data->win_ptr
		= mlx_new_window(window_data->mlx_ptr, window_size, window_size, "fdf");
	if (window_data->win_ptr == NULL)
		return (free(window_data), NULL);
	mlx_clear_window(window_data->mlx_ptr, window_data->win_ptr);
	return (window_data);
}

void	control_mlx_window(t_window_data *window_data)
{
	mlx_key_hook(window_data->win_ptr, key_hook, window_data);
	mlx_loop(window_data->mlx_ptr);
}
