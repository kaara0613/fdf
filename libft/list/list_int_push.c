/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:38:23 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 16:13:04 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

static t_list	*allocation_list(void);

void	list_int_push(t_list **list, int n)
{
	t_list	*head;

	head = *list;
	if (*list == NULL)
	{
		*list = allocation_list();
		(*list)->element.i = n;
		return ;
	}
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = allocation_list();
		head->next->element.i = n;
	}
}

static t_list	*allocation_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->next = NULL;
	return (list);
}
