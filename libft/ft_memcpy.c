/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:50:36 by youhan            #+#    #+#             */
/*   Updated: 2021/12/02 18:48:24 by youhan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

void	ft_memcpy(void *dest, const void *source, unsigned int num)
{
	char		*dest_point;
	const char	*source_point;

	dest_point = dest;
	source_point = source;
	while (num > 0)
	{
		dest_point[num - 1] = source_point[num - 1];
		num--;
	}
}
