/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/16 20:31:20 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int			main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack *b;
	int		cnt;

	cnt = 0;
	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	set_stack(argc, argv, a);
	find_index(a->head, a);
	atob(a->total, a, b);
}
