/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:31:07 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:38:09 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "ft_printf.h"
#include <stdio.h>

void	list_int_print(t_list *list)
{
	int		i;
	t_list	*head;

	i = 0;
	head = list;
	if (head == NULL)
		return ;
	while (head != NULL)
	{
		ft_printf("%d : ", i);
		i++;
		ft_printf("%d\n", head->element.i);
		head = head->next;
	}
}
