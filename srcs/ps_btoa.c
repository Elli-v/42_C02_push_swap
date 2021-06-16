/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:37:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/16 16:54:50 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void btoa(int total, t_stack *a, t_stack *b)
{
	t_node *node;
	int max;
	int post_max;
	int mid_node;
	int cnt;
	int temp;

	if (total <= 1)
	{
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
		max = (a->head->index) - 1;
		post_max = max - 1;
		mid_node = total / 2;
		cnt = 0;
		temp = total;
		node = b->head;
		while (temp--)
		{
			if (max != node->index)
			{
				node = node->next;
				cnt++;
			}
			else if (max == node->index)
				break;
		}
		while (node->prev)
			node = node->prev;
		if (cnt > mid_node)
		{
			cnt = total - cnt;
			while (cnt--)
			{
				reverse_rotate_stack(b, B);
				if (b->head->index == post_max)
					push_stack(b, a, A);
			}
		}
		else
		{
			while (cnt--)
			{
				rotate_stack(b, B);
				if (b->head->index == post_max)
				{
					cnt--;
					push_stack(b, a, A);
				}
			}
		}
	}
	push_stack(b, a, A);
	if (a->head->index > a->head->next->index)
		swap_stack(a, A);
	if (b->total != 0)
		btoa(b->total, a, b);
}
