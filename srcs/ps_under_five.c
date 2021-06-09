/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 02:54:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/10 05:21:20 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void two_index_a(t_stack *a)
{
	if (a->head->index > a->head->next->index)
		swap_stack(a, A);
}

void three_same(t_stack *a, int max, int min)
{
	if ((a->head->index == min && a->head->next->next->index != max) ||
		(a->head->index != min && a->head->next->next->index == max) ||
		(a->head->index == max && a->head->next->next->index == min))
		swap_stack(a, A);
	if (a->head->index == max && a->head->next->next->index != min)
		rotate_stack(a, A);
	else if (a->head->index != max && a->head->next->next->index == min)
		reverse_rotate_stack(a, A);
}

void three_notsame(t_stack *a, int max, int min)
{
	if ((a->head->index == max && a->head->next->next->index != min) ||
		(a->head->index != min && a->head->next->next->index == max))
		swap_stack(a, A);
	if ((a->head->index == min && a->head->next->next->index != max) ||
		(a->head->index != max && a->head->next->next->index == min) ||
		(a->head->index == max && a->head->next->next->index == min))
	{
		rotate_stack(a, A);
		swap_stack(a, A);
		reverse_rotate_stack(a, A);
	}
}

void three_index_a(t_stack *a, int total)
{
	int min;
	int max;

	min = min_index(a->head, total);
	max = max_index(a->head, total);
	if (a->total == total)
		three_same(a, max, min);
	else
	{
		three_notsame(a, max, min);
		three_notsame(a, max, min);
	}
}

void four_index(t_stack *a, t_stack *b, int real_total)
{
	int min;
	int total;

	total = real_total;
	min = min_index(a->head, total);
	while (total--)
	{
		if (a->head->index == min)
			push_stack(a, b, B);
		rotate_stack(a, A);
	}
	three_index_a(a, 3);
	push_stack(b, a, A);
}

void five_index_a(t_stack *a, t_stack *b, int real_total)
{
	int total;
	int mid;
	int min;
	int max;

	min = min_index(a->head, real_total);
	max = max_index(a->head, real_total);
	mid = (min + max) / 2;
	total = real_total;
	while (total--)
	{
		if (a->head->index >= mid)
			rotate_stack(a, A);
		else
			push_stack(a, b, B);
	}
	three_index_a(a, a->total);
	if (b->head->index < b->head->next->index)
		swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}