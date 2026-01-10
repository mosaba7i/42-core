/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:43:30 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:43:31 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*cur;

	if (!b || !*b || !(*b)->next)
		return ;
	first = pop_front(b);
	cur = *b;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}
