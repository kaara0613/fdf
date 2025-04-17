/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_pop_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:36:54 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:37:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>
#include <stdlib.h>

int	list_int_pop_back(t_list **list)
{
	int		result;
	t_list	*head;

	head = *list;
	while (head->next == NULL)
		head = head->next;
	result = list_int_pop(&head);
	return (result);
}
