/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:48:38 by kaara             #+#    #+#             */
/*   Updated: 2025/04/26 10:34:46 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	print_c(int c);
int	print_s(char *str);
int	print_d_i(int di);
int	print_i(int i);
int	print_u(unsigned int u);
int	print_x(unsigned long x);
int	print_upper_x(unsigned long x);
int	print_p(void *ptr);
int	printf_putnbr(int n);
int	ft_printf(const char *format, ...);
int	d_print_c(int c);
int	d_print_s(char *str);
int	d_print_d_i(int di);
int	d_print_i(int i);
int	d_print_u(unsigned int u);
int	d_print_x(unsigned long x);
int	d_print_upper_x(unsigned long x);
int	d_print_p(void *ptr);
int	d_printf_putnbr(int n);
int	ft_dprintf(const char *format, ...);

#endif
