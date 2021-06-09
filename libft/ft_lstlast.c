/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:04:58 by soooh             #+#    #+#             */
/*   Updated: 2020/11/18 11:15:40 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list	*cnt;

	if (lst == NULL)
		return (NULL);
	cnt = lst;
	while (cnt->next != NULL)
		cnt = cnt->next;
	return (cnt);
}
