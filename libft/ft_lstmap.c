/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:52:57 by chaepark          #+#    #+#             */
/*   Updated: 2021/11/11 15:03:50 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_lst;
	t_list	*new_lst;
	t_list	*tmp;

	begin_lst = lst;
	new_lst = 0;
	while (begin_lst)
	{
		tmp = ft_lstnew(f(begin_lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, tmp);
		begin_lst = begin_lst->next;
	}
	return (new_lst);
}
