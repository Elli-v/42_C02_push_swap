/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:49:56 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 02:56:48 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				ps_free_a(t_stack *a)
{
	t_node			*node;
	t_node			*temp;

	node = a->head;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(a);
}

void				ps_free_b(t_stack *b)
{
	t_node			*node;
	t_node			*temp;

	node = b->head;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(b);
}

void				ps_free_all(t_stack *a, t_stack *b)
{
	ps_free_a(a);
	ps_free_b(b);
}
