/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 17:01:28 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					ps_sort(t_stack *a)
{
	t_node			*node;

	node = a->head;
	while (node)
	{
		if (node->next)
		{
			if (node->index > node->next->index)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->index == a->tail->index)
		return (1);
	else
		return (0);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
		set_stack(argc, argv, a);
		find_index(a->head, a);
		if (ps_sort(a))
			return (0);
		atob(a->total, a, b);
		ps_free_all(a, b);
	}
	return (0);
}
