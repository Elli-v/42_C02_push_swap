/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:50 by soooh             #+#    #+#             */
/*   Updated: 2021/06/13 22:09:38 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void atob(int total, t_stack *a, t_stack *b)
{
	t_sort sort;
	int temp;

	// printf("atob !\n");
	temp = total;
	init_sort(&sort);
	// printf("temp = %d\n", temp);
	if (temp < 6)
	{
		under_five_a(a, b, temp);
		return;
	}
	select_pivot(&sort, a);
	// printf("s = %d >><< b = %d\n", sort.s_pivot, sort.b_pivot);
	while (temp--)
	{
		if (a->head->index > sort.b_pivot)
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
	// just_check(a, b);
	temp = sort.cnt_pb - sort.cnt_rb;
	// while (temp--)
	// {
	// 	push_stack(b, a, A);
	// 	reverse_rotate_stack(b, B);
	// }
	atob(a->total, a, b);
	// just_check(a, b);
	if (b->total != 0)
		btoa(b->total, a, b);
	// just_check(a, b);
}