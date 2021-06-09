/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:44:25 by soooh             #+#    #+#             */
/*   Updated: 2020/11/21 12:13:37 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	i = 0;
	if (*s2 == '\0')
		return (char *)(s1);
	while (s1[i] && (i < len))
	{
		if (len - i < ft_strlen(s2))
			return (char *)(NULL);
		if (ft_cmp(&s1[i], s2) == 1)
			return ((char *)&s1[i]);
		i++;
	}
	return (char *)(NULL);
}
