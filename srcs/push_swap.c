/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/13 21:16:00 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void just_check(t_stack *a, t_stack *b)
{
	int i;
	t_node *node;

	i = 0;
	node = a->head;
	printf("\n[ A ]\n");
	while (i++ < a->total)
	{
		printf("%d(%d), ", node->data, node->index);
		if (node->next)
			node = node->next;
	}
	printf("\n");
	i = 0;
	node = b->head;
	printf("\n[ B ]\n");
	while (i++ < b->total)
	{
		printf("%d(%d),", node->data, node->index);
		if (node->next)
			node = node->next;
	}
	printf("\n-------------------\n");
}

int main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	int cnt;

	// 메모리 누수 검사는 했나요? >> 다 만들고 할게요옹~
	// printf("main argc = %d\n", argc);
	cnt = 0;
	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	set_stack(argc, argv, a);
	find_index(a->head, a);
	atob(a->total, a, b);
	// just_check(a, b);
	// if (b->total != 0)
	// 	btoa(b->total, a, b);
	// just_check(a, b);
}