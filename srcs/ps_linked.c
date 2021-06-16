/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_linked.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:15:42 by soooh             #+#    #+#             */
/*   Updated: 2021/06/16 16:55:11 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void				connect_node(t_node *temp, t_node **node, t_stack *a)
{
	if (!*node)
	{
		*node = temp;
		a->head = temp;
	}
	else
	{
		(*node)->next = temp;
		temp->prev = *node;
		*node = (*node)->next;
	}
}

int					make_node(char *argv, t_node **node, t_stack *a)
{
	t_node			*temp;


	temp = init_node();
	if (!temp)
		return (0);
	temp->data = ps_atoi(argv);
	connect_node(temp, node, a);
	a->total++;
	return (1);
}

void				duplicate_data(t_node *node)
{
	int				data;
	t_node			*temp;

	while (node->next)
	{
		temp = node->next;
		data = node->data;
		while (temp)
		{
			if (temp->data == data)
				ps_error(SAME_NUM);
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		node = node->next;
	}
	
}

void				set_stack(int argc, char **argv, t_stack *a)
{
	int				i;
	int				stack;
	t_node			*node;
	t_node			*temp;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		stack = make_node(argv[i], &node, a);
		if (!stack)
			ps_error(BASIC);
	}
	temp = a->head;
	while (temp)
		temp = temp->next;
	if (node->next == NULL)
		a->tail = node;
	while(node->prev)
		node = node->prev;
	duplicate_data((t_node *)a->head);	
}
