/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:50 by soooh             #+#    #+#             */
/*   Updated: 2021/06/09 03:20:31 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int three_to_five_a(t_stack *a, t_stack *b, int total)
{
	if (total <= 3)
	{
		three_index_a(a, total);
		return (0);
	}
	else if (total == 5)
	{
		five_index_a(a, b, total);
		return (0);
	}
	else
		return (1);
}

void three_index_a(t_stack *a, int total)
{
	int min;
	int max;

	min = min_index(a->head, total);
	max = max_index(a->head, total);
	printf("min = %d >><< max = %d\n total = %d\n", min, max, total);
	if (a->total == 3)
	{
		if ((a->head->index == min && a->tail->index != max) ||
			(a->head->index != min && a->tail->index == max) ||
			(a->head->index == max && a->tail->index == min))
			swap_stack(a, A);
		if (a->head->index == max && a->tail->index != min)
			rotate_stack(a, A);
		else if (a->head->index != max && a->tail->index == min)
			reverse_rotate_stack(a, A);
	}
	else if (total == 3)
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
	else if (total == 2)
	{
		if (a->head->index > a->head->next->index)
			swap_stack(a, A);
	}
}

void five_index_a(t_stack *a, t_stack *b, int real_total)
{
	int total;
	int pivot;
	int min;
	int max;

	min = min_index(a->head, real_total);
	max = max_index(a->head, real_total);
	pivot = (min + max) / 2;
	total = real_total;
	while (total--)
	{
		if (a->head->index >= pivot)
			rotate_stack(a, A);
		else
			push_stack(a, b, B);
	}
	three_index_a(a, total);
	if (b->head->index < b->head->next->index)
		swap_stack(b, B);
	push_stack(b, a, A);
	push_stack(b, a, A);
}

void atob(int total, t_stack *a, t_stack *b, int cnt)
{
	t_sort sort;
	int temp;
	int temp2;

	printf("\natob in !\n");
	temp = total;
	init_sort(&sort);

	printf("before total = %d\n", total);
	if (!three_to_five_a(a, b, total))
		return;
	select_pivot(&sort, a);
	printf("s.p = %d >>><<< b.p = %d\n", sort.s_pivot, sort.b_pivot);
	while (temp--)
	{
		if (a->head->index >= sort.b_pivot)
		{
			rotate_stack(a, A);
			sort.cnt_ra++;
		}
		else
		{
			push_stack(a, b, B);
			sort.cnt_pb++;
			if (b->head->index <= sort.s_pivot)
			{
				rotate_stack(b, B);
				sort.cnt_rb++;
			}
		}
	}
	// ra한 만큼 rrr을 해서 a 스택은 그대로 두고 s.pivot 보다 작은 수를 b스택 위로 보내기 위함
	if (sort.cnt_ra > sort.cnt_rb)
	{
		temp = sort.cnt_rb;
		temp2 = sort.cnt_ra - sort.cnt_rb;
		if ((cnt) > 0)
		{
			while (temp--)
				reverse_double_rotate(a, b, ALL);
			while (temp2--)
				reverse_rotate_stack(a, A);
		}
		else
		{
			while (temp--)
				reverse_rotate_stack(b, B);
		}
	}
	else
	{
		temp = sort.cnt_ra;
		temp2 = sort.cnt_rb - temp;
		if ((cnt) > 0)
		{
			while (temp--)
				reverse_double_rotate(a, b, ALL);
			while (temp2--)
				reverse_rotate_stack(b, B);
		}
		else
		{
			while (temp--)
				reverse_rotate_stack(a, A);
		}
	}
	printf("ra = %d\n", sort.cnt_ra);
	printf("rb = %d\n", sort.cnt_rb);
	printf("pb = %d\n", sort.cnt_pb);
	atob(sort.cnt_ra, a, b, cnt);
	just_check(a, b);
	btoa(sort.cnt_rb, a, b, &cnt);
	just_check(a, b);
	btoa((sort.cnt_pb - sort.cnt_rb), a, b, &cnt);
}
