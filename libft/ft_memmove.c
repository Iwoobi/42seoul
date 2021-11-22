/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:13:50 by youhan            #+#    #+#             */
/*   Updated: 2021/11/18 21:13:50 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *memmove (void *dest, const void *src, unsigned int num)
{
	char		*dest_point;
	const char	*src_point;

	dest_point = dest;
	src_point = src;
	if (dest_point < src_point)
	{
		while (num > 0)
			*dest_point = *src_point;
	}
	else
	{
		int i;

		i = 0;
		while (num > i)
		{
			*dest_point = *src_point;
			i++;
		}
	}
}
