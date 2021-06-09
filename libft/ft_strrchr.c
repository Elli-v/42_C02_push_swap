/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:36:36 by soooh             #+#    #+#             */
/*   Updated: 2020/10/09 15:02:16 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			temp = (char *)str + i;
		i++;
	}
	if (c == 0)
		return (char *)(str + i);
	return (temp);
}
