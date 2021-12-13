/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:09:14 by youhan            #+#    #+#             */
/*   Updated: 2021/12/13 13:19:23 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_next_lst;
	t_list	*save_address;

	if (lst)
		new_lst = ft_lstnew(f(lst->content));
	while (lst)
	{
		save_address = lst->next;
		ft_lstdelone(lst, del);
		lst = save_address;
		if (lst)
		{
			new_next_lst = ft_lstnew(f(lst->content));
			ft_lstadd_back(&new_lst, new_next_lst);
		}	
	}
	return (new_lst);
}
