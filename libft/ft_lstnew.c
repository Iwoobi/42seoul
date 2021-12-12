/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:56:10 by youhan            #+#    #+#             */
/*   Updated: 2021/12/13 00:56:10 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*new_address;

	new_address = (t_list *)malloc(sizeof(t_list));
	if (!new_address)
		return (NULL);
	else
	{
		new_address->content = content;
		new_address->next = NULL;
	}
	return (new_address);
}
