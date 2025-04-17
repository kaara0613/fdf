/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_clone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:34:40 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:35:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "stdlib.h"

t_list	*list_int_clone(t_list *list)
{
	t_list	*head;
	t_list	*list_clone;

	list_clone = NULL;
	head = list;
	while (head != NULL)
	{
		list_int_push(&list_clone, head->element.i);
		head = head->next;
	}
	return (list_clone);
}
