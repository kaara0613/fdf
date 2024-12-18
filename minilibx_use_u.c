/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx_use_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:25 by kaara             #+#    #+#             */
/*   Updated: 2024/12/18 01:35:43 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, void *param)
{
	t_window_data	*window_data;

	window_data = (t_window_data *)param;
	printf("keycode %d\n", keycode);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(window_data.mlx_ptr, window_data.win_ptr);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
