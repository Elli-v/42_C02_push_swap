/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:41:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/31 02:08:20 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ps_putendl_fd(char *s, int fd)
{
	int			i;

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

void			ps_error(int flag)
{
	if (flag == BASIC)
		ps_putendl_fd("ERROR !", 1);
	else if (flag == INT_RANGE)
		ps_putendl_fd("ERROR : INT Range !", 1);
	else if (flag == MALLOC_ERR)
		ps_putendl_fd("ERROR : malloc allocation failed !", 1);
	else if (flag == NO_NUM)
		ps_putendl_fd("ERROR : enter numbers only !", 1);
	else if (flag == SAME_NUM)
		ps_putendl_fd("ERROR : Duplicate values !", 1);
	exit(0);
}

int				ps_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	numb;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	numb = 0;
	i = -1;
	while (str[++i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ps_error(NO_NUM);
		if (str[i] >= '0' && str[i] <= '9')
			numb = (numb * 10) + (str[i] - 48);
	}
	numb = sign * numb;
	if (numb > INT_MAX || numb < (- INT_MAX - 1))
		ps_error(INT_RANGE);
	return (numb);
}
