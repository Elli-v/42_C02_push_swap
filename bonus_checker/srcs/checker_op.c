/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 02:35:31 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 02:35:33 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				ck_reverse_rotate(t_stack *a, t_stack *b, char *buf)
{
	if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'a')
		reverse_rotate_stack(a, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'b')
		reverse_rotate_stack(b, 0);
	else if (buf[0] == 'r' && buf[1] == 'r' && buf[2] == 'r')
		reverse_double_rotate(a, b, 0);
}

void				ck_rotate(t_stack *a, t_stack *b, char *buf)
{
	if (buf[0] == 'r' && buf[1] == 'a')
		rotate_stack(a, 0);
	else if (buf[0] == 'r' && buf[1] == 'b')
		rotate_stack(b, 0);
	else if (buf[0] == 'r' && buf[1] == 'r')
		rotate_rotate(a, b, 0);
}

void				ck_swap(t_stack *a, t_stack *b, char *buf)
{
	if (buf[0] == 's' && buf[1] == 'a')
		swap_stack(a, 0);
	else if (buf[0] == 's' && buf[1] == 'b')
		swap_stack(b, 0);
	else if (buf[0] == 's' && buf[1] == 's')
		swap_swap(a, b, 0);
}

void				ck_push(t_stack *a, t_stack *b, char *buf)
{
	if (buf[0] == 'p' && buf[1] == 'a')
		push_stack(b, a, 0);
	else if (buf[0] == 'p' && buf[1] == 'b')
		push_stack(a, b, 0);
}

void				checker_op(t_stack *a, t_stack *b, char *buf)
{
	if (buf[0] == 'p' && ft_strlen(buf) == 2)
		ck_push(a, b, buf);
	else if (buf[0] == 's' && ft_strlen(buf) == 2)
		ck_swap(a, b, buf);
	else if (buf[0] == 'r' && ft_strlen(buf) == 2)
		ck_rotate(a, b, buf);
	else if (buf[0] == 'r' && buf[1] == 'r' && ft_strlen(buf) == 3)
		ck_reverse_rotate(a, b, buf);
	else
		ps_error(BASIC);
}
