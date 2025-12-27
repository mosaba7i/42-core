/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:45:48 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 11:15:36 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_node **a)
{
	if (*a && (*a)->next && (*a)->val > (*a)->next->val)
		sa(a);
}

static void	sort_three(t_node **a)
{
	int	a0;
	int	a1;
	int	a2;

	if (!*a || !(*a)->next || !(*a)->next->next)
		return ;
	a0 = (*a)->val;
	a1 = (*a)->next->val;
	a2 = (*a)->next->next->val;
	if (a0 > a1 && a1 < a2 && a0 < a2)
		sa(a);
	else if (a0 > a1 && a1 > a2)
	{
		sa(a);
		rra(a);
	}
	else if (a0 > a1 && a1 < a2 && a0 > a2)
		ra(a);
	else if (a0 < a1 && a1 > a2 && a0 < a2)
	{
		sa(a);
		ra(a);
	}
	else if (a0 < a1 && a1 > a2 && a0 > a2)
		rra(a);
}

static void	push_min_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	sz;
	int	i;
	int	limit;

	pos = get_min_pos(*a);
	sz = list_size(*a);
	i = 0;
	if (pos <= sz / 2)
		limit = pos;
	else
		limit = sz - pos;
	while (i++ < limit)
	{
		if (pos <= sz / 2)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
}

void	sort_small(t_node **a, t_node **b)
{
	int	sz;

	sz = list_size(*a);
	if (sz == 2)
		sort_two(a);
	else if (sz == 3)
		sort_three(a);
	else if (sz == 4)
	{
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else if (sz == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
