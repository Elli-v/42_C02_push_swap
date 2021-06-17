/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:47:33 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 02:56:45 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int					ck_sort(t_stack *a)
{
	t_node			*node;

	node = a->head;
	while (node)
	{
		if (node->next)
		{
			if (node->index > node->next->index)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->index == a->tail->index)
		return (1);
	else
		return (0);
}

void				checker(t_stack *a, t_stack *b)
{
	char			*buf;

	while (get_next_line(0, &buf) > 0)
	{
		checker_op(a, b, buf);
		free(buf);
	}
	free(buf);
	if (ck_sort(a) && !(b->head))
		ps_putendl_fd("OK", 1);
	else
		ps_putendl_fd("KO", 1);
}

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc == 2)
		ps_error(BASIC);
	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
		set_stack(argc, argv, a);
		find_index(a->head, a);
		checker(a, b);
		ps_free_all(a, b);
	}
	return (0);
}
