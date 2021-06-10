/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:37:18 by soooh             #+#    #+#             */
/*   Updated: 2021/06/10 22:36:03 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_to_a(t_stack *a, t_stack *b, int total)
{
	int	r;

	r = total;
	while (r--)
		push_stack(b, a, A);
}

void	under_five_b(t_stack *a, t_stack *b, int total)
{
	if (total == 2)
	{
		push_to_a(a, b, total);
		two_index_a(a);
	}
	else if (total == 3)
	{
		push_to_a(a, b, total);
		three_index_a(a, total);
	}
	else if (total == 4)
	{
		push_to_a(a, b, total);
		four_index(a, b, total);
	}
	else if (total == 5)
	{
		push_to_a(a, b, total);
		five_index_a(a, b, total);
	}
}

void	btoa(int total, t_stack *a, t_stack *b)
{
	t_sort sort;
	int		temp;

	printf("btoa !\n");
	temp = total;
	init_sort(&sort);
	if (temp < 6)
	{
		under_five_b(a, b, temp);
		return ;
	}
	select_pivot(&sort, b);
	printf("s = %d >><< b = %d\n", sort.s_pivot, sort.b_pivot);
	while (temp--)
	{
		if (b->head->index <= sort.s_pivot)
		{
			rotate_stack(b, B);
			sort.cnt_rb++;
		}
		else
		{
			push_stack(b, a, A);
			sort.cnt_pa++;
			if (a->head->index <= sort.b_pivot)
			{
				rotate_stack(a, A);
				sort.cnt_ra++;
			}
		}
	}
	just_check(a, b);
	printf("ra = %d\nrb = %d\npa = %d\n", sort.cnt_ra, sort.cnt_rb, sort.cnt_pa);
	temp = sort.cnt_ra;
	while (temp--)
	{
		reverse_rotate_stack(a, A);
		push_stack(a, b, B);
	}
	atob(sort.cnt_pa - sort.cnt_ra, a, b);
	btoa(b->total, a, b);
}



// void btoa(int total, t_stack *a, t_stack *b, int *cnt)
// {
// 	t_sort sort;
// 	int temp;

// 	(*cnt)++;
// 	// printf("\n btoa in !\n");
// 	temp = total;
// 	init_sort(&sort);
// 	// printf("total //= %d\n", total);
// 	if (!three_to_five_b(a, b, total))
// 		return;
// 	select_pivot(&sort, b);
// 	// printf("s.p = %d >>><<< b.p = %d\n", sort.s_pivot, sort.b_pivot);
// 	// printf("B // temp = %d\n", temp);
// 	while (temp--)
// 		sort_push_b(a, b, &sort);
// 	// printf("pa = %d ra = %d\n", sort.cnt_pa, sort.cnt_ra);
// 	atob((sort.cnt_pa - sort.cnt_ra), a, b, *cnt);
// 	if (sort.cnt_ra > sort.cnt_rb)
// 	{
// 		temp = sort.cnt_rb;
// 		while (temp--)
// 			reverse_double_rotate(a, b, ALL);
// 		temp = sort.cnt_ra - sort.cnt_rb;
// 		while (temp--)
// 			reverse_rotate_stack(a, A);
// 	}
// 	else
// 	{
// 		temp = sort.cnt_ra;
// 		while (temp--)
// 			reverse_double_rotate(a, b, ALL);
// 		temp = sort.cnt_rb - sort.cnt_ra;
// 		while (temp--)
// 			reverse_rotate_stack(b, B);
// 	}
// 	atob(sort.cnt_rb, a, b, *cnt);
// 	btoa(sort.cnt_ra, a, b, cnt);
// }