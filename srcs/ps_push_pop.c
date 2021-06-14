/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:03:04 by soooh             #+#    #+#             */
/*   Updated: 2021/06/14 17:23:19 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void reverse_rotate_stack(t_stack *stack, int flag)
{
	t_node *temp;
	t_node *temp_prev;

	if (stack->total < 2)
		return;
	temp = stack->tail;
	temp_prev = stack->tail->prev;
	stack->head->prev = temp;
	temp->next = stack->head;
	temp->prev = NULL;
	stack->head = temp;
	stack->tail = temp_prev;
	stack->tail->next = NULL;
	if (flag == A)
		ps_putendl_fd("rra", 1);
	else if (flag == B)
		ps_putendl_fd("rrb", 1);
}

void rotate_stack(t_stack *stack, int flag)
{
	t_node *temp;

	if (stack->total < 2)
		return;
	temp = stack->head;
	stack->head = stack->head->next;
	stack->tail->next = temp;
	temp->prev = stack->tail;
	stack->tail = temp;
	stack->head->prev = NULL;
	stack->tail->next = NULL;
	if (flag == A)
		ps_putendl_fd("ra", 1);
	else if (flag == B)
		ps_putendl_fd("rb", 1);
}

void swap_stack(t_stack *stack, int flag)
{
	t_node *temp;

	if (stack->total < 2)
		return;
	temp = stack->head;
	stack->head->prev = stack->head->next;
	stack->head->next = stack->head->next->next;
	stack->head = stack->head->prev;
	stack->head->next = temp;
	stack->head->prev = NULL;
	if (stack->total == 3)
	{
		stack->tail = stack->head->next->next;
		stack->tail->prev = stack->head->next;
		stack->tail->prev->prev = stack->head;
	}
	if (stack->total == 2)
		stack->tail = stack->head->next;
	if (flag == A)
		ps_putendl_fd("sa", 1);
	else if (flag == B)
		ps_putendl_fd("sb", 1);
}

void push_stack_one(t_stack *from, t_stack *to)
{
	if (to->total == 0)
	{
		to->head = from->head;
		to->tail = to->head;
	}
	else
	{
		to->head->prev = from->head;
		from->head->next = to->head;
		to->head = to->head->prev;
	}
	from->head = NULL;
	from->tail = NULL;
}

void push_stack(t_stack *from, t_stack *to, int flag)
{
	if (from->total == 1)
		push_stack_one(from, to);
	else
	{
		if (to->total == 0)
		{
			to->head = from->head;
			to->tail = to->head;
			from->head = from->head->next;
			from->head->prev = NULL;
			to->head->next = NULL;
		}
		else
		{
			to->head->prev = from->head;
			from->head = from->head->next;
			from->head->prev = NULL;
			to->head->prev->next = to->head;
			to->head = to->head->prev;
		}
	}
	to->total++;
	from->total--;
	if (flag == A)
		ps_putendl_fd("pa", 1);
	else if (flag == B)
		ps_putendl_fd("pb", 1);
	if (from->total == 0)
		return;
}
