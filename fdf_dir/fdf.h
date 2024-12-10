/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:09:34 by kaara             #+#    #+#             */
/*   Updated: 2024/12/10 22:31:05 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>

# define BUFFER_SIZE 42

typedef struct s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct s_coordinate_data
{
	int	z;
	int	colar;
}	t_coordinate_data;

int	**make_map(int fd, t_coordinate *max);

#endif