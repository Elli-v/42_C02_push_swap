/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:24:17 by soooh             #+#    #+#             */
/*   Updated: 2021/06/10 22:00:06 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int min_index(t_node *node, int total)
{
	int min;

	min = node->index;
	while (total--)
	{
		if (min > node->index)
			min = node->index;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int max_index(t_node *node, int total)
{
	int max;

	max = node->index;
	while (total--)
	{
		if (max < node->index)
			max = node->index;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

void select_pivot(t_sort *sort, t_stack *stack)
{
	int min;
	int mid;
	int max;

	min = min_index(stack->head, stack->total);
	max = max_index(stack->head, stack->total);
	mid = (min + max) / 2;
	sort->b_pivot = (mid + max) / 2;
	sort->s_pivot = (min + mid) / 2;
}

void sort_reverse(t_stack *a, t_stack *b, t_sort *sort, int flag)
{
	int rrr;
	int rem;

	if (flag == A)
	{
		rrr = sort->cnt_rb;
		rem = sort->cnt_ra - rrr;
		while (rrr--)
			reverse_double_rotate(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	if (flag == B)
	{
		rrr = sort->cnt_ra;
		rem = sort->cnt_rb - rrr;
		while (rrr--)
			reverse_double_rotate(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
}

void sort_push_b(t_stack *a, t_stack *b, t_sort *sort)
{
	if (b->head->index < sort->s_pivot)
	{
		rotate_stack(b, B);
		sort->cnt_rb++;
	}
	else
	{
		push_stack(b, a, A);
		sort->cnt_pa++;
		if (b->head->index >= sort->b_pivot)
		{
			if (b->head->index < sort->s_pivot)
				rotate_rotate(a, b, B);
			else
			{
				rotate_stack(a, A);
				sort->cnt_ra++;
			}
		}
	}
}

void sort_push_a(t_stack *a, t_stack *b, t_sort *sort)
{
	if (a->head->index > sort->b_pivot)
	{
		rotate_stack(a, A);
		sort->cnt_ra++;
	}
	else
	{
		push_stack(a, b, B);
		sort->cnt_pb++;
		if (b->head->index <= sort->s_pivot)
		{
			if (b->head->index <= sort->s_pivot)
				rotate_rotate(a, b, A);
			else
			{
				rotate_stack(b, B);
				sort->cnt_rb++;
			}
		}
	}
}
