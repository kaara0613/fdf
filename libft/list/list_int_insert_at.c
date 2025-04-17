/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_insert_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:35:31 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:35:47 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <stdlib.h>

void	list_int_insert_at(t_list **list, int n, int i)
{
	int		idx;
	t_list	*head;
	t_list	*tmp;

	idx = 0;
	head = *list;
	tmp = NULL;
	list_int_push(&tmp, n);
	if (i == 0)
	{
		tmp->next = *list;
		*list = tmp;
	}
	else
	{
		while (head->next != NULL && idx < i - 1)
		{
			head = head->next;
			idx++;
		}
		tmp->next = head->next;
		head->next = tmp;
	}
}
