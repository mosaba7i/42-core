/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:45:53 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:44:34 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int val)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->val = val;
	n->index = 0;
	n->next = NULL;
	return (n);
}

void	push_front(t_node **head, t_node *n)
{
	if (!n)
		return ;
	n->next = *head;
	*head = n;
}

t_node	*pop_front(t_node **head)
{
	t_node	*n;

	if (!head || !*head)
		return (NULL);
	n = *head;
	*head = (*head)->next;
	n->next = NULL;
	return (n);
}

t_node	*get_min_node(t_node *head)
{
	t_node	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head)
	{
		if (head->val < min->val)
			min = head;
		head = head->next;
	}
	return (min);
}

int	get_min_pos(t_node *head)
{
	int		pos;
	int		idx;
	t_node	*cur;
	int		min;

	pos = 0;
	idx = 0;
	cur = head;
	min = 2147483647;
	while (cur)
	{
		if (cur->val < min)
		{
			min = cur->val;
			pos = idx;
		}
		idx++;
		cur = cur->next;
	}
	return (pos);
}
