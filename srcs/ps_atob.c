/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:50 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 03:31:35 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				re_one_third(t_stack *a, t_stack *b, t_sort *sort)
{
	if (b->head->index >= sort->s_pivot &&
	b->head->index < sort->b_pivot)
		rotate_stack(b, B);
	else
	{
		push_stack(b, a, A);
		sort->cnt_pa++;
		if (a->head->index <= sort->b_pivot)
		{
			rotate_stack(a, A);
			sort->cnt_ra++;
		}
	}
}

void				re_btoa(int total, t_stack *a, t_stack *b)
{
	t_sort			sort;
	int				temp;

	temp = total;
	init_sort(&sort);
	select_pivot_b(&sort, b);
	while (temp--)
		re_one_third(a, b, &sort);
	temp = sort.cnt_ra;
	while (sort.cnt_ra--)
		reverse_rotate_stack(a, A);
	while (sort.cnt_pa--)
	{
		push_stack(a, b, B);
		if (a->head->index > sort.hiden_pivot)
			rotate_stack(b, B);
	}
}

void				ps_atob_div(t_stack *a, t_stack *b, t_sort *sort)
{
	if (a->head->index > sort->b_pivot)
		rotate_stack(a, A);
	else
	{
		push_stack(a, b, B);
		if (b->head->index > sort->s_pivot)
			rotate_stack(b, B);
	}
}

void				atob(int total, t_stack *a, t_stack *b)
{
	t_sort			sort;
	int				temp;

	init_sort(&sort);
	temp = total;
	if (temp < 6)
	{
		if (temp > 1)
			under_five(a, b, temp);
		return ;
	}
	select_pivot(&sort, a);
	while (temp--)
		ps_atob_div(a, b, &sort);
	if (b->total > 100 && b->total < 200)
		re_btoa(b->total, a, b);
	atob(a->total, a, b);
	if (b->total != 0)
		btoa(b->total, a, b);
}
