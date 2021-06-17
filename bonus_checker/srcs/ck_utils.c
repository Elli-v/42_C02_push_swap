/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:41:10 by soooh             #+#    #+#             */
/*   Updated: 2021/06/17 23:23:25 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void				ps_putendl_fd(char *s, int fd)
{
	int				i;

	if (s == NULL)
		return (void)(NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	write(fd, "\n", 1);
}

void				push_stack_one(t_stack *from, t_stack *to)
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

void				ps_error(int flag)
{
	if (flag == BASIC)
		ps_putendl_fd("Error", 2);
	else if (flag == INT_RANGE)
		ps_putendl_fd("Error", 2);
	else if (flag == MALLOC_ERR)
		ps_putendl_fd("Error", 2);
	else if (flag == NO_NUM)
		ps_putendl_fd("Error", 2);
	else if (flag == SAME_NUM)
		ps_putendl_fd("Error", 2);
	exit(0);
}

int					ps_atoi(const char *str)
{
	int				sign;
	long long		numb;
	int				i;

	numb = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ps_error(NO_NUM);
		if (str[i] >= '0' && str[i] <= '9')
			numb = (numb * 10) + (str[i] - 48);
	}
	numb = sign * numb;
	if (numb > INT_MAX || numb < (-INT_MAX - 1))
		ps_error(INT_RANGE);
	return (numb);
}
