/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handle_format2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:09:13 by kaara             #+#    #+#             */
/*   Updated: 2025/04/02 17:57:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	print_x(unsigned long x)
{
	int		i;
	int		temp;
	char	*hex_digits;
	char	result[21];

	i = 0;
	temp = 0;
	if (x == 0)
	{
		temp++;
		write(1, "0", 1);
	}
	hex_digits = "0123456789abcdef";
	while (x)
	{
		result[i++] = hex_digits[x % 16];
		x = x / 16;
	}
	result[i] = '\0';
	temp += i;
	while (i)
		write (1, &result[--i], 1);
	return (temp);
}

int	print_upper_x(unsigned long x)
{
	int		i;
	int		temp;
	char	*hex_digits;
	char	result[21];

	i = 0;
	temp = 0;
	if (x == 0)
	{
		temp++;
		write(1, "0", 1);
	}
	hex_digits = "0123456789ABCDEF";
	while (x)
	{
		result[i++] = hex_digits[x % 16];
		x = x / 16;
	}
	result[i] = '\0';
	temp += i;
	while (i)
		write (1, &result[--i], 1);
	return (temp);
}

int	print_p(void *ptr)
{
	int				len;
	unsigned long	addr;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		len = 5;
		return (len);
	}
	addr = (unsigned long)ptr;
	len = 2;
	write(1, "0x", 2);
	len += print_x(addr);
	return (len);
}
