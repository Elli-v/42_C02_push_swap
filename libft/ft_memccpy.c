/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:17:59 by soooh             #+#    #+#             */
/*   Updated: 2020/10/09 11:19:37 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == (unsigned char)c)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
