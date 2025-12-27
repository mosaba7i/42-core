/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:43:36 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:43:37 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*cur;
	t_node	*last;
	t_node	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	cur = *a;
	prev = NULL;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	last = cur;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
