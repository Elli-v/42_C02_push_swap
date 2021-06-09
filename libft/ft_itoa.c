/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:46:46 by soooh             #+#    #+#             */
/*   Updated: 2020/11/11 21:44:56 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(int n)
{
	int			i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static int		ft_negaposi(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

char			*ft_itoa(int n)
{
	char		*b2c;
	int			i;

	i = ft_len(n);
	if (!(b2c = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	if (n == 0)
		b2c[0] = '0';
	else if (n < 0)
		b2c[0] = '-';
	b2c[i] = '\0';
	while (n)
	{
		b2c[--i] = ft_negaposi(n % 10) + '0';
		n = n / 10;
	}
	return (b2c);
}
