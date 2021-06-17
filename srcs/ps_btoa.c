/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:37:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 01:03:53 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				ps_push_max_down(t_stack *a, t_stack *b, int cnt)
{
	while (cnt--)
	{
		rotate_stack(b, B);
		if (b->head->index == b->post_max)
		{
			cnt--;
			push_stack(b, a, A);
		}
	}
}

void				ps_push_max_up(t_stack *a, t_stack *b, int cnt)
{
	while (cnt--)
	{
		reverse_rotate_stack(b, B);
		if (b->head->index == b->post_max)
			push_stack(b, a, A);
	}
}

void				ps_push_max(t_stack *a, t_stack *b, int cnt)
{
	int				total;
	int				mid_num;

	total = b->total;
	mid_num = total / 2;
	if (cnt > mid_num)
	{
		cnt = total - cnt;
		ps_push_max_up(a, b, cnt);
	}
	else
		ps_push_max_down(a, b, cnt);
}

int					ps_search_max(t_stack *b)
{
	t_node			*node;
	int				temp;
	int				cnt;

	temp = b->total;
	node = b->head;
	cnt = 0;
	while (temp--)
	{
		if (b->max != node->index)
		{
			node = node->next;
			cnt++;
		}
		else if (b->max == node->index)
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (cnt);
}

void				btoa(int total, t_stack *a, t_stack *b)
{
	int				mid_node;
	int				cnt;

	if (total == 1)
	{
		push_stack(b, a, A);
		return ;
	}
	else
	{
		b->max = (a->head->index) - 1;
		b->post_max = (b->max) - 1;
		mid_node = total / 2;
		cnt = ps_search_max(b);
		ps_push_max(a, b, cnt);
	}
	push_stack(b, a, A);
	if (a->head->index > a->head->next->index)
		swap_stack(a, A);
	if (b->total != 0)
		btoa(b->total, a, b);
}
