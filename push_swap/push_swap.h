/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malsabah <malsabah@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:40:56 by malsabah          #+#    #+#             */
/*   Updated: 2025/12/25 12:40:57 by malsabah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				val;
	int				index;
	struct s_node	*next;
}					t_node;

t_node				*parse_args(int argc, char **argv);
void				free_list(t_node *head);
int					list_size(t_node *head);
int					is_sorted(t_node *head);

void				normalize(t_node *head);
void				radix_sort(t_node **a, t_node **b);

void				sort_small(t_node **a, t_node **b);

t_node				*node_new(int val);
void				push_front(t_node **head, t_node *n);
t_node				*pop_front(t_node **head);
t_node				*get_min_node(t_node *head);
int					get_min_pos(t_node *head);

void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);
void				pa(t_node **a, t_node **b);
void				pb(t_node **a, t_node **b);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

#endif
