/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:54:13 by soooh             #+#    #+#             */
/*   Updated: 2020/10/19 16:39:40 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	else
	{
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = start;
		j = 0;
		while (i < start + len)
			str[j++] = (char)s[i++];
	}
	str[j] = '\0';
	return (str);
}
