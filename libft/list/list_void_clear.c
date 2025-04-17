/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_void_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:31:19 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:47:15 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

void	list_void_clear(t_list *list)
{
	t_list	*head;

	if (list == NULL)
		return ;
	head = list;
	list_void_clear(head->next);
	free(head);
}
