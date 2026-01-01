/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:37:14 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:39:18 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (list_size(*a) <= 5)
		sort_small(a, &b);
	else
	{
		normalize(*a);
		radix_sort(a, &b);
	}
	free_list(b);
}

int	main(int argc, char **argv)
{
	t_node	*a;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	if (!a)
		return (0);
	if (!is_sorted(a))
		run_sort(&a);
	free_list(a);
	return (0);
}
