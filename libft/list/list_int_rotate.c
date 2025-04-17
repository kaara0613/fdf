/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_int_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaara <kaara@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:39:53 by kaara             #+#    #+#             */
/*   Updated: 2025/04/14 15:40:03 by kaara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	list_int_rotate(t_list **list)
{
	int	tmp;

	tmp = list_int_pop(list);
	list_int_push(list, tmp);
}
