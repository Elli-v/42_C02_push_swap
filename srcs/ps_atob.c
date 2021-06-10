/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:04:50 by soooh             #+#    #+#             */
/*   Updated: 2021/06/10 22:37:36 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"



// void _atob(int total, t_stack *a, t_stack *b, int cnt)
// {
// 	t_sort sort;
// 	int temp;
// 	int temp2;

// 	// printf("\natob in !\n");
// 	temp = total;
// 	init_sort(&sort);
// 	if (total <= 5)
// 	{
// 		three_to_five_a(a, b, total);
// 		return;
// 	}
// 	// if (!three_to_five_a(a, b, total))
// 	// 	return;
// 	select_pivot(&sort, a);
// 	// printf("s.p = %d >>><<< b.p = %d\n", sort.s_pivot, sort.b_pivot);
// 	while (temp--)
// 	{
// 		sort_push_a(a, b, &sort);
// 		// printf("짜증나\n");
// 		// ra한 만큼 rrr을 해서 a 스택은 그대로 두고 s.pivot 보다 작은 수를 b스택 위로 보내기 위함
// 	}
// 	if (sort.cnt_ra > sort.cnt_rb)
// 	{
// 		temp = sort.cnt_rb;
// 		temp2 = sort.cnt_ra - sort.cnt_rb;
// 		if ((cnt) > 0)
// 		{
// 			while (temp--)
// 				reverse_double_rotate(a, b, ALL);
// 			while (temp2--)
// 				reverse_rotate_stack(a, A);
// 		}
// 		else
// 		{
// 			while (temp--)
// 				reverse_rotate_stack(b, B);
// 		}
// 	}
// 	else
// 	{
// 		temp = sort.cnt_ra;
// 		temp2 = sort.cnt_rb - temp;
// 		if ((cnt) > 0)
// 		{
// 			while (temp--)
// 				reverse_double_rotate(a, b, ALL);
// 			while (temp2--)
// 				reverse_rotate_stack(b, B);
// 		}
// 		else
// 		{
// 			while (temp--)
// 				reverse_rotate_stack(a, A);
// 		}
// 	}

// 	// printf("ra = %d\n", sort.cnt_ra);
// 	// printf("rb = %d\n", sort.cnt_rb);
// 	// printf("pb = %d\n", sort.cnt_pb);
// 	just_check(a, b);
// 	printf("pb =  %d\n", sort.cnt_pb);
// 	atob(sort.cnt_ra, a, b, cnt);
// 	btoa(sort.cnt_rb, a, b, &cnt);
// 	// // just_check(a, b);
// 	// btoa((sort.cnt_pb - sort.cnt_rb), a, b, &cnt);
// }

void	atob(int total, t_stack *a, t_stack *b)
{
	t_sort sort;
	int		temp;

	printf("atob !\n");
	temp = total;
	init_sort(&sort);
	// printf("temp = %d\n", temp);
	if (temp < 6)
	{
		under_five_a(a, b, temp);
		return ;
	}
	select_pivot(&sort, a);
	printf("s = %d >><< b = %d\n", sort.s_pivot, sort.b_pivot);
	while (temp--)
	{
		if (a->head->index > sort.b_pivot)
		{
			rotate_stack(a, A);
			sort.cnt_ra++;
		}
		else
		{
			push_stack(a, b, B);
			sort.cnt_pb++;
			if (b->head->index <= sort.s_pivot)
			{
				rotate_stack(b, B);
				sort.cnt_rb++;
			}
		}
	}
	just_check(a, b);
	printf("ra = %d\nrb = %d\npb = %d\n", sort.cnt_ra, sort.cnt_rb, sort.cnt_pb);
	temp = sort.cnt_pb - sort.cnt_rb;
	while (temp--)
	{
		push_stack(b, a, A);
		reverse_rotate_stack(b, B);
	}
	atob(sort.cnt_ra, a, b);
	just_check(a, b);
	btoa(sort.cnt_pb - sort.cnt_rb, a, b);
	just_check(a, b);
}