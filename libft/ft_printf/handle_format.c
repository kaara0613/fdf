/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:59:08 by kaara             #+#    #+#             */
/*   Updated: 2024/12/04 15:11:34 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_putnbr_fd(int n, int fd);

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		len = 6;
		write(1, "(null)", len);
		return (len);
	}
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

int	print_u(unsigned int u)
{
	int		i;
	int		temp;
	char	result[10];

	i = 0;
	temp = 0;
	if (u == 0)
	{
		temp++;
		write(1, "0", 1);
	}
	while (u)
	{
		result[i++] = u % 10 + '0';
		u /= 10;
	}
	temp += i;
	while (i > 0)
		write(1, &result[--i], 1);
	return (temp);
}

int	print_d_i(int di)
{
	int	count;
	int	di_temp;

	di_temp = di;
	if (di <= 0)
		count = 1;
	else
		count = 0;
	while (di_temp)
	{
		di_temp /= 10;
		count++;
	}
	ft_putnbr_fd(di, 1);
	return (count);
}

static void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	un;
	char			result[11];

	i = 0;
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0)
	{
		write (fd, "-", 1);
		un = (unsigned int)-n;
	}
	else
		un = (unsigned int)n;
	while (un)
	{
		result[i++] = un % 10 + '0';
		un /= 10;
	}
	while (i > 0)
		write (fd, &result[--i], 1);
}
