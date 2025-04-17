/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42.jp>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 02:45:25 by kaara             #+#    #+#             */
/*   Updated: 2025/03/30 15:58:11 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ministr;
	size_t	actual_len;

	actual_len = ft_strlen(s);
	if (actual_len <= start)
	{
		ministr = (char *)malloc(1);
		if (ministr)
			ministr[0] = '\0';
		else
			return (NULL);
		return (ministr);
	}
	if (actual_len - start < len)
		len = actual_len - start;
	ministr = (char *)malloc(len + 1);
	if (!ministr)
		return (NULL);
	ft_strlcpy (ministr, s + start, len + 1);
	return (ministr);
}
