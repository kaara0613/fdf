/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:10:45 by kaara             #+#    #+#             */
/*   Updated: 2025/03/26 20:37:40 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

static int	check_str(const char find, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	n;
	size_t	result_size;
	char	*result;

	i = 0;
	n = ft_strlen(s1);
	while (check_str(s1[i], set) == 1)
		i++;
	while (n > i && check_str(s1[n - 1], set) == 1)
		n--;
	result_size = n - i + 1;
	result = (char *)malloc(result_size);
	if (!result)
		return (NULL);
	ft_strlcpy (result, &s1[i], result_size);
	return (result);
}

static int	check_str(const char find, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == find)
			return (1);
		i++;
	}
	return (0);
}
