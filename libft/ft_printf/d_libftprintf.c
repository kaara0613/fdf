/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_libftprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:59:27 by kaara             #+#    #+#             */
/*   Updated: 2025/04/26 10:34:01 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static int	check_par(const char *format, va_list *args);

int	ft_dprintf(const char *format, ...)
{
	int		total_len;
	va_list	args;

	total_len = 1;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				total_len += check_par(format, &args);
		}
		else
		{
			write(2, format, 1);
			total_len++;
		}
		format++;
	}
	va_end(args);
	return (total_len - 1);
}

static int	check_par(const char *format, va_list *args)
{
	int	total_len;

	total_len = 0;
	if (*format == 'c')
		total_len += d_print_c(va_arg(*args, int));
	else if (*format == 's')
		total_len += d_print_s(va_arg(*args, char *));
	else if (*format == 'p')
		total_len += d_print_p(va_arg(*args, void *));
	else if (*format == 'd' || *format == 'i')
		total_len += d_print_d_i(va_arg(*args, int));
	else if (*format == 'u')
		total_len += d_print_u(va_arg(*args, unsigned int));
	else if (*format == 'x')
		total_len += d_print_x(va_arg(*args, unsigned int));
	else if (*format == 'X')
		total_len += d_print_upper_x(va_arg(*args, unsigned int));
	else if (*format == '%')
	{
		write(2, "%", 1);
		total_len++;
	}
	return (total_len);
}
