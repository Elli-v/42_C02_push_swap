/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:37:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/09 03:16:37 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int three_to_five_b(t_stack *a, t_stack *b, int total)
{
	if (total <= 3)
	{
		three_index_b(a, b, total);
		return (0);
	}
	else if (total == 5)
	{
		five_index_b(a, b, total);
		return (0);
	}
	else
	{
		return (1);
	}
}

void three_index_b(t_stack *a, t_stack *b, int total)
{
	int min;
	int max;

	min = min_index(b->head, total);
	max = max_index(b->head, total);
	printf("min = %d >><< max = %d\n total = %d\n", min, max, total);
	printf("now index = %d\n", b->head->index);
	if (b->total == 3)
	{
		if ((b->head->index == max && b->tail->index != min) ||
			(b->head->index != max && b->tail->index == min) ||
			(b->head->index == min && b->tail->index == max))
			swap_stack(b, B);
		if (b->head->index == min && b->head->next->next->index != max)
			rotate_stack(b, B);
		else if (b->head->index != min && b->head->next->next->index == max)
			reverse_rotate_stack(b, B);
	}
	else if (b->total > 3 && total == 3)
	{
		if ((b->head->index == max && b->head->next->next->index != min) ||
			(b->head->index != max && b->head->next->next->index == min) ||
			(b->head->index == min && b->head->next->next->index == max))
			swap_stack(b, B);
		if (b->head->index == min && b->head->next->next->index != max)
			rotate_stack(b, B);
		else if (b->head->index != min && b->head->next->next->index == max)
			reverse_rotate_stack(b, B);
	}
	else if (total == 2)
	{
		if (b->head->index < b->head->next->index)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
	}
	else if (total == 1)
	{
		if (b->head->index < b->head->next->index)
			swap_stack(b, B);
		push_stack(b, a, A);
	}
}

void five_index_b(t_stack *a, t_stack *b, int real_total)
{
	int total;
	int pivot;
	int min;
	int max;

	printf("******total = %d\n", real_total);
	min = min_index(b->head, real_total);
	max = max_index(b->head, real_total);
	pivot = (min + max) / 2;
	total = real_total;
	while (total--)
	{
		if (b->head->index >= pivot)
			push_stack(b, a, A);
		else
			rotate_stack(b, B);
	}
	three_index_a(a, 3);
	if (b->head->index < b->head->next->index)
		swap_stack(b, B);
	push_stack(a, b, B);
	push_stack(a, b, B);
}

void btoa(int total, t_stack *a, t_stack *b, int *cnt)
{
	t_sort sort;
	int temp;

	(*cnt)++;
	printf("\n btoa in !\n");
	temp = total;
	init_sort(&sort);
	printf("total = %d\n", total);
	if (!three_to_five_b(a, b, total))
		return;
	select_pivot(&sort, b);
	printf("s.p = %d >>><<< b.p = %d\n", sort.s_pivot, sort.b_pivot);
	printf("B // temp = %d\n", temp);
	while (temp--)
	{
		if (b->head->index < sort.s_pivot)
		{
			rotate_stack(b, B);
			sort.cnt_rb++;
		}
		else
		{
			push_stack(b, a, A);
			sort.cnt_pa++;
			if (b->head->index >= sort.b_pivot)
			{
				rotate_stack(a, A);
				sort.cnt_ra++;
			}
		}
	}
	printf("pa = %d ra = %d\n", sort.cnt_pa, sort.cnt_ra);
	atob((sort.cnt_pa - sort.cnt_ra), a, b, *cnt);
	if (sort.cnt_ra > sort.cnt_rb)
	{
		temp = sort.cnt_rb;
		while (temp--)
			reverse_double_rotate(a, b, ALL);
		temp = sort.cnt_ra - sort.cnt_rb;
		while (temp--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		temp = sort.cnt_ra;
		while (temp--)
			reverse_double_rotate(a, b, ALL);
		temp = sort.cnt_rb - sort.cnt_ra;
		while (temp--)
			reverse_rotate_stack(b, B);
	}
	atob(sort.cnt_rb, a, b, *cnt);
	btoa(sort.cnt_ra, a, b, cnt);
}