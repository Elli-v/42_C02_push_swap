/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:02 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 03:32:32 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int					main(int argc, char *argv[])
{
	t_stack			*a;
	t_stack			*b;

	if (argc > 1)
	{
		a = init_stack();
		b = init_stack();
		set_stack(argc, argv, a);
		find_index(a->head, a);
		atob(a->total, a, b);
		ps_free_all(a, b);
	}
	return (0);
}
