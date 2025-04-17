/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:46:42 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:46:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "stdlib.h"
#include <stdbool.h>

static void	swap(t_list **list, int n);

t_list	*list_int_sort(t_list *list)
{
	t_list	*result;

	result = list_int_clone(list);
	swap(&result, list_int_count(list));
	return (result);
}

void	swap(t_list **list, int n)
{
	int		idx1;
	int		idx2;
	bool	swapped;

	idx1 = 0;
	while (idx1 < n - 1)
	{
		idx2 = 0;
		swapped = false;
		while (idx2 < n - 1 - idx1)
		{
			if (list_int_access_at(*list, idx2)
				> list_int_access_at(*list, idx2 + 1))
			{
				list_int_insert_at(list, list_int_pop_at(list, idx2), idx2 + 1);
				swapped = true;
			}
			idx2++;
		}
		if (!swapped)
			break ;
		idx1++;
	}
}
