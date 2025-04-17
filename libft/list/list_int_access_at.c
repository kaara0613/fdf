/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_access_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:34:13 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:34:24 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	list_int_access_at(t_list *list, int i)
{
	int		idx;
	t_list	*head;

	idx = 0;
	head = list;
	while (head->next != NULL && idx < i)
	{
		head = head->next;
		idx++;
	}
	return (head->element.i);
}
