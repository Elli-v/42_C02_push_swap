/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_prev_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 00:43:38 by soooh             #+#    #+#             */
/*   Updated: 2021/06/05 19:53:15 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					max(t_node *node, int total)
{
	int				max;

	max = node->data;
	while (total--)
	{
		if (max < node->data)
			max = node->data;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

void				give_index(t_node *node, t_stack *stack, int index, int min)
{
	int				i;

	i = 0;
	while (i++ < stack->total)
	{
		if (min == node->data)
			node->index = index;
		if (node->next)
			node = node->next;
	}
}

void				find_index(t_node *node, t_stack *stack)
{
	int				index;
	int				i;
	int				min;
	int				x_min;

	index = 0;
	while (index++ < stack->total)
	{
		i = 0;
		min = max(node, stack->total);
		while (i++ < stack->total)
		{
			if (min > node->data && (index == 1 || x_min < node->data))
				min = node->data;
			if (node->next)
				node = node->next;
		}
		node = stack->head;
		give_index(node, stack, index, min);
		node = stack->head;
		x_min = min;
	}

}
