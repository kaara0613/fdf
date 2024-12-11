/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:29:44 by kaara             #+#    #+#             */
/*   Updated: 2024/12/11 19:03:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	make_mlx_window(t_window_data *window_data)
{
	window_data->mlx_ptr = mlx_init();
	if (!window_data->mlx_ptr)
	{
		perror("minilibx conecting");
		exit(EXIT_FAILURE);
	}
	mlx_new_window(window_data->mlx_ptr, 500, 500, "fdf");
	if (!window_data->win_ptr)
	{
		perror("minilibx making window");
		exit(EXIT_FAILURE);
	}
	mlx_clear_window(window_data->mlx_ptr, window_data->win_ptr);
}

void	control_mlx_window(t_window_data *window_data)
{
	mlx_key_hook(window_data->win_ptr, key_hook, window_data);
	mlx_loop(window_data->mlx_ptr);
}
