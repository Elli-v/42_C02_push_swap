/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 11:45:43 by soooh             #+#    #+#             */
/*   Updated: 2020/10/17 15:52:14 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	size_t	i;
	char	*mem;

	mem = (char *)malloc(ft_strlen(src) + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (src[i])
	{
		mem[i] = src[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
