/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:45:33 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 10:45:34 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	bits;
	int	i;
	int	size;

	if (!a || !*a || list_size(*a) <= 1)
		return ;
	bits = get_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		size = list_size(*a);
		while (size--)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
