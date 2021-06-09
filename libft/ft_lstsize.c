/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:19:13 by soooh             #+#    #+#             */
/*   Updated: 2020/11/16 12:25:35 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	if (lst == NULL)
		return (0);
	else
	{
		while (lst->next != NULL)
		{
			len++;
			lst = lst->next;
		}
		len++;
		return (len);
	}
}
