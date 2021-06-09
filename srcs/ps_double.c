/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 01:53:27 by soooh             #+#    #+#             */
/*   Updated: 2021/05/31 01:53:35 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				reverse_double_rotate(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate_stack(a, flag);
	reverse_rotate_stack(b, flag);
	if (flag == ALL)
		ps_putendl_fd("rrr", 1);
}

void				rotate_rotate(t_stack *a, t_stack *b, int flag)
{
	rotate_stack(a, flag);
	rotate_stack(b, flag);
	if (flag == ALL)
		ps_putendl_fd("rr", 1);
}

void				swap_swap(t_stack *a, t_stack *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == ALL)
		ps_putendl_fd("ss", 1);
}