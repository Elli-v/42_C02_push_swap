/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:25:59 by soooh             #+#    #+#             */
/*   Updated: 2020/11/21 11:54:40 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			*ft_move(unsigned char *dest, unsigned char *src, size_t n)
{
	size_t			i;

	i = 0;
	if (dest > src)
	{
		while (i < n)
		{
			dest[n - i - 1] = src[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (dest);
}

void				*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	tmp_dest = ft_move(tmp_dest, tmp_src, n);
	return (dest);
}
