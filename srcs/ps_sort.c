/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:24:17 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 01:04:53 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					min_index(t_node *node, int total)
{
	int				min;

	min = node->index;
	while (total--)
	{
		if (min > node->index)
			min = node->index;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int					max_index(t_node *node, int total)
{
	int				max;

	max = node->index;
	while (total--)
	{
		if (max < node->index)
			max = node->index;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

void				select_pivot_b(t_sort *sort, t_stack *stack)
{
	int				min;
	int				max;

	min = min_index(stack->head, stack->total);
	max = max_index(stack->head, stack->total);
	sort->s_pivot = (min + max) / 3;
	sort->b_pivot = sort->s_pivot * 2;
	sort->hiden_pivot = ((sort->b_pivot) + max) / 2;
}

void				select_pivot(t_sort *sort, t_stack *stack)
{
	int				min;
	int				max;
	int				temp;

	temp = 0;
	min = min_index(stack->head, stack->total);
	max = max_index(stack->head, stack->total);
	sort->b_pivot = (min + max) / 2;
	if ((sort->b_pivot - min) > 70)
	{
		temp = (sort->b_pivot - min) / 2;
		sort->b_pivot = min + temp;
	}
	sort->s_pivot = (min + sort->b_pivot) / 2;
}
