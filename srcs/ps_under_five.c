/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 02:54:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 01:05:08 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					find_mid(t_stack *stack, int total)
{
	int				min;
	int				max;

	min = min_index(stack->head, total);
	max = max_index(stack->head, total);
	return ((min + max) / 2);
}

void				three_index(t_stack *a, int total)
{
	int				min;
	int				max;

	total = 0;
	min = min_index(a->head, a->total);
	max = max_index(a->head, a->total);
	if ((a->head->index == min && a->head->next->next->index != max) ||
		(a->head->index != min && a->head->next->next->index == max) ||
		(a->head->index == max && a->head->next->next->index == min))
		swap_stack(a, A);
	if (a->head->index == max && a->head->next->next->index != min)
		rotate_stack(a, A);
	else if (a->head->index != max && a->head->next->next->index == min)
		reverse_rotate_stack(a, A);
}

void				four_index(t_stack *a, t_stack *b, int real_total)
{
	int				min;
	int				total;
	int				ra;

	ra = 0;
	total = real_total;
	min = min_index(a->head, a->total);
	while (total--)
	{
		if (a->head->index == min)
			push_stack(a, b, B);
		rotate_stack(a, A);
	}
	three_index(a, 3);
	push_stack(b, a, A);
}

void				five_index(t_stack *a, t_stack *b, int real_total)
{
	int				total;
	int				mid;
	int				ra;
	int				pb;

	ra = 0;
	pb = 0;
	mid = find_mid(a, real_total);
	total = real_total;
	while (total--)
	{
		if (a->head->index >= mid)
			rotate_stack(a, A);
		else
			push_stack(a, b, B);
	}
	three_index(a, 3);
	if (b->head->index < b->head->next->index)
		swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

void				under_five(t_stack *a, t_stack *b, int total)
{
	if (total == 2)
	{
		if (a->head->index > a->head->next->index)
			swap_stack(a, A);
	}
	else if (total <= 3)
		three_index(a, total);
	else if (total == 4)
		four_index(a, b, total);
	else if (total == 5)
		five_index(a, b, total);
}
