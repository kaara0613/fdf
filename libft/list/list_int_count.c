/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:35:13 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:35:23 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

int	list_int_count(t_list *list)
{
	int		result;
	t_list	*head;

	result = 0;
	head = list;
	while (head->next != NULL)
	{
		result++;
		head = head->next;
	}
	return (result + 1);
}
