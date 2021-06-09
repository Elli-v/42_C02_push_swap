/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:41:10 by soooh             #+#    #+#             */
/*   Updated: 2021/05/23 20:51:45 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*int	ft_atoi(const char *str)
{
	int	res;
	int	negative;
	int count;

	count = 0;
	negative = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	negative = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
		count++;
	}
	res = res * negative;
	if (count >= 19 && negative == 1)
		return (-1);
	else if (count >= 19 && negative == -1)
		return (0);
	return (res);
}*/

int		ft_atoi(const char *str)
{
	int	i;
	int	numb;

	i = 0;
	numb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (ft_strlen(&str[i]) > 10)
			return (9999);
		if (numb > 2147483647)
			return (-1);
		else if (numb < -2147483648)
			return (0);
		else
			numb = (numb * 10) + (str[i] - 48);
		i++;
	}
	return (numb);
}

int				ft_atoi_rgb(const char *str)
{
	int			i;
	int			sign;
	long long	numb;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' ||
			str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	numb = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (sign * numb > 2147483647)
			return (-1);
		else if (sign * numb < -2147483648)
			return (0);
		else
			numb = (numb * 10) + (str[i] - 48);
		i++;
	}
	return (sign * numb);
}