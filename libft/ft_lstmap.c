/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:09:14 by youhan            #+#    #+#             */
/*   Updated: 2021/12/15 20:09:42 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_next_lst;

	if (lst)
		new_lst = ft_lstnew(f(lst->content));	
	else
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		new_next_lst = ft_lstnew(f(lst->content));
		if (!new_next_lst)
		{
			ft_lstclear(&new_lst,del);
			return (NULL);
		} 
		ft_lstadd_back(&new_lst,new_next_lst);
	}
	return (new_lst);
}
