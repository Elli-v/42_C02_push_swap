/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/08 19:39:23 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void just_check(t_stack *a, t_stack *b)
{
	int i;
	t_node *node;

	i = 0;
	node = a->head;
	printf("A\n");
	while (i++ < a->total)
	{
		printf("%d(%d), ", node->data, node->index);
		if (node->next)
			node = node->next;
	}
	printf("\n");
	i = 0;
	node = b->head;
	printf("B\n");
	while (i++ < b->total)
	{
		printf("%d(%d),", node->data, node->index);
		if (node->next)
			node = node->next;
	}
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
		ps_error(BASIC);
	a = init_stack();
	b = init_stack();
	set_stack(argc, argv, a);
	find_index(a->head, a);
	just_check(a, b);
	atob(a->total, a, b, cnt);
	just_check(a, b);
	// printf("restart\n");
	// atob(a->total, a, b);
	// just_check(a, b);
}