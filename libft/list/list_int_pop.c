/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:37:14 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:37:38 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "list.h"
#include <stdlib.h>

int	list_int_pop(t_list **list)
{
	t_list	*head;
	int		result;

	head = *list;
	*list = head->next;
	result = head->element.i;
	head->next = NULL;
	free(head);
	return (result);
}
