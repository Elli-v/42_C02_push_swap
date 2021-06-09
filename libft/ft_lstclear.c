/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:08:04 by soooh             #+#    #+#             */
/*   Updated: 2020/11/21 13:58:31 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;

	delnode = (*lst);
	(*lst) = (*lst)->next;
	del(delnode->content);
	free(delnode);
	while (*lst)
	{
		delnode = (*lst);
		(*lst) = (*lst)->next;
		del(delnode->content);
		free(delnode);
	}
}
