/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:43:26 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:43:27 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*cur;

	if (!a || !*a || !(*a)->next)
		return ;
	first = pop_front(a);
	cur = *a;
	while (cur->next)
		cur = cur->next;
	cur->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}
