/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:37:49 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/27 03:05:27 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_number(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atoi(const char *s, long *out)
{
	int	sign;
	long	num;
	int	i;

	sign = 1;
	num = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	*out = num * sign;
	return (1);
}

static void	push_value(t_node **head, int val)
{
	t_node	*n;
	t_node	*cur;

	n = node_new(val);
	if (!n)
		return ;
	if (!*head)
		*head = n;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = n;
	}
}

static int	has_duplicates(t_node *head)
{
	t_node	*p;
	t_node	*q;

	p = head;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (q->val == p->val)
				return (1);
			q = q->next;
		}
		p = p->next;
	}
	return (0);
}

t_node	*parse_args(int argc, char **argv)
{
	t_node	*head;
	int		i;
	long		value;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || !check_number(argv[i]) || !ft_atoi(argv[i], &value))
			break ;
		if (value > INT_MAX || value < INT_MIN)
			break;
		push_value(&head, value);
		
		i++;
	}
	if (i < argc || has_duplicates(head))
	{
		write(2, "Error\n", 6);
		free_list(head);
		return (NULL);
	}
	return (head);
}
