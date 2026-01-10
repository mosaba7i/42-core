/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:43:49 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:43:50 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = pop_front(b);
	second = pop_front(b);
	push_front(b, first);
	push_front(b, second);
	write(1, "sb\n", 3);
}
