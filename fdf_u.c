/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 01:44:30 by kaara             #+#    #+#             */
/*   Updated: 2025/01/01 15:15:52 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	reset_map_index(t_coordinate	*map_size)
{
		map_size->x_i = 0;
		map_size->y_i = 0;
}

//int配列をスペース区切りで文字列にする。
//配列の先頭は先頭を除いた配列の要素数とする。
char	*int_array_to_string(int *arr)
{
	ssize_t	arr_i;
	ssize_t	line_i;
	char	*line;

	arr_i = 1;
	line_i = 0;
	line = (char *)malloc(sizeof(char) * arr_spc_len(arr) + 1);
	if (line == NULL)
		return (NULL);
	while (arr_i <= arr[0])
	{
		ft_memcpy(line + line_i, itoa(arr[arr_i]),
			sizeof(char) * intlen(arr[arr_i]));
		line_i += intlen(arr[arr_i]);
		if (arr_i != arr[0])
		{
			line_i++;
			line[line_i] = ' ';
		}
		else
			line[line_i + 1] = '\0';
	}
	return (line);
}

ssize_t	arr_spc_len(int *arr)
{
	ssize_t	arr_i;
	ssize_t	string_len;

	arr_i = 1;
	while (nums_arr <= arr[0])
	{
		string_len += intlen(arr[num_arr]);
		arr_i++;
	}
	string_len += arr[0] - 1;
	return (string_len);
}

ssize_t	intlen(int src)
{
	ssize_t			len;
	unsigned int	u_src;

	len = 0;
	if (src < 0)
	{
		u_src = (nusigined int)src;
		len++;
	}
	while (src != 0)
	{
		src /= 10;
		len++;
	}
	return (len);
}
