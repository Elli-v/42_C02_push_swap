/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_under_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 02:54:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/10 21:37:38 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int min_mid_max(t_stack *stack, int total, int flag)
{
	int min;
	int max;

	if (flag == MIN)
		return (min_index(stack->head, total));
	else if (flag == MAX)
		return (max_index(stack->head, total));
	else if (flag == MID)
	{
		min = min_index(stack->head, total);
		max = max_index(stack->head, total);
		return ((min + max) / 2);
	}
	return (0);
}

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

	min = min_mid_max(a, total, MIN);
	max = min_mid_max(a, total, MAX);
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
	int ra;

	ra = 0;
	total = real_total;
	min = min_mid_max(a, total, MIN);
	if (a->total == 4)
	{
		while (total--)
		{
			if (a->head->index == min)
				push_stack(a, b, B);
			rotate_stack(a, A);
		}
	}
	else
	{
		while (total--)
		{
			if (a->head->index == min)
			{
				push_stack(a, b, B);
				break;
			}
			rotate_stack(a, A);
			ra++;
		}
		while (ra--)
			reverse_rotate_stack(a, A);
	}
	three_index_a(a, 3);
	push_stack(b, a, A);
}

void five_index_a(t_stack *a, t_stack *b, int real_total)
{
	int total;
	int mid;
	int ra;
	int pb;

	ra = 0;
	pb = 0;
	mid = min_mid_max(a, real_total, MID);
	total = real_total;
	if (a->total == 5)
	{
		while (total--)
		{
			if (a->head->index >= mid)
				rotate_stack(a, A);
			else
				push_stack(a, b, B);
		}
	}
	else
	{
		while (total--)
		{
			if (a->head->index >= mid)
			{
				rotate_stack(a, A);
				ra++;
			}
			else
			{
				push_stack(a, b, B);
				pb++;
				if (pb == 2)
					break;
			}
		}
		while (ra--)
			reverse_rotate_stack(a, A);
	}
	three_index_a(a, 3);
	if (b->head->index < b->head->next->index)
		swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

void	under_five_a(t_stack *a, t_stack *b, int total)
{
	if (total == 2)
		two_index_a(a);
	else if (total <= 3)
		three_index_a(a, total);
	else if (total == 4)
		four_index(a, b, total);
	else if (total == 5)
		five_index_a(a, b, total);
}

