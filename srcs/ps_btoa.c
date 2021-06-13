/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:37:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/13 17:15:14 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// void push_to_a(t_stack *a, t_stack *b, int total)
// {
// 	int r;
//
// 	r = total;
// 	while (r--)
// 		push_stack(b, a, A);
// }
//
// void under_five_b(t_stack *a, t_stack *b, int total)
// {
// 	if (total == 2)
// 	{
// 		push_to_a(a, b, total);
// 		two_index_a(a);
// 	}
// 	else if (total == 3)
// 	{
// 		push_to_a(a, b, total);
// 		three_index_a(a, total);
// 	}
// 	else if (total == 4)
// 	{
// 		push_to_a(a, b, total);
// 		four_index(a, b, total);
// 	}
// 	else if (total == 5)
// 	{
// 		push_to_a(a, b, total);
// 		five_index_a(a, b, total);
// 	}
// }
//
// void btoa(int total, t_stack *a, t_stack *b)
// {
// 	t_sort sort;
// 	int temp;
//
// 	printf("btoa !\n");
// 	temp = total;
// 	init_sort(&sort);
// 	if (temp < 6)
// 	{
// 		under_five_b(a, b, temp);
// 		return;
// 	}
// 	select_pivot(&sort, b);
// 	printf("s = %d >><< b = %d\n", sort.s_pivot, sort.b_pivot);
// 	while (temp--)
// 	{
// 		if (b->head->index <= sort.s_pivot)
// 		{
// 			rotate_stack(b, B);
// 			sort.cnt_rb++;
// 		}
// 		else
// 		{
// 			push_stack(b, a, A);
// 			sort.cnt_pa++;
// 			if (a->head->index <= sort.b_pivot)
// 			{
// 				rotate_stack(a, A);
// 				sort.cnt_ra++;
// 			}
// 		}
// 	}
// 	just_check(a, b);
// 	printf("ra = %d\nrb = %d\npa = %d\n", sort.cnt_ra, sort.cnt_rb, sort.cnt_pa);
// 	temp = sort.cnt_ra;
// 	while (temp--)
// 	{
// 		reverse_rotate_stack(a, A);
// 		push_stack(a, b, B);
// 	}
// 	atob(sort.cnt_pa - sort.cnt_ra, a, b);
// 	btoa(b->total, a, b);
// }

void btoa(int total, t_stack *a, t_stack *b)
{
	int large_index;
	int mid_node;
	int cnt;
	int temp;
	t_node *node;

	// printf("btoa !\n");
	if (total <= 1)
	{
		// printf("\ntotal = %d\n", total);
		// printf("\nlast pang!!\n\n");
		if (total == 1)
		{
			push_stack(b, a, A);
			return;
		}
		else
			return;
	}
	else
	{
		large_index = (a->head->index) - 1;
		mid_node = total / 2;
		cnt = 0;
		temp = total;
		node = b->head;
		while (temp--)
		{
			if (large_index != node->index)
			{
				node = node->next;
				cnt++;
			}
			else if (large_index == node->index)
				break;
		}
		while (node->prev)
			node = node->prev;
		// printf("cnt = %d\n", cnt);
		if (cnt > mid_node)
		{
			cnt = total - cnt;
			while (cnt--)
				reverse_rotate_stack(b, B);
		}
		else
		{
			while (cnt--)
				rotate_stack(b, B);
		}
		// printf("head->index = %d\n", b->head->index);
		push_stack(b, a, A);
		// just_check(a, b);
		if (b->total != 0)
			btoa(b->total, a, b);
	}
}