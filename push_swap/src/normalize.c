/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:36:50 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:36:51 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	normalize(t_node *head)
{
	t_node	*cur;
	int		cnt;
	t_node	*s;

	cur = head;
	while (cur)
	{
		cnt = 0;
		s = head;
		while (s)
		{
			if (s->val < cur->val)
				cnt++;
			s = s->next;
		}
		cur->index = cnt;
		cur = cur->next;
	}
}
