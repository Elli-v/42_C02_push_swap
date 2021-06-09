/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:09:09 by soooh             #+#    #+#             */
/*   Updated: 2020/10/14 20:38:18 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*arr1;
	unsigned char	*arr2;

	arr1 = (unsigned char *)str1;
	arr2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (arr1[i] == arr2[i])
			i++;
		else
			return (arr1[i] - arr2[i]);
	}
	return (0);
}
