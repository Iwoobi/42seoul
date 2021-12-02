/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:47:49 by youhan            #+#    #+#             */
/*   Updated: 2021/12/02 18:33:01 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	size_t = 0;
	while (*src != '\0')
	{
		if (size - 1 > 0)
		{
			*dest++ = *src;
			size--;
		}
		src++;
		i++;
	}
	*dest = '\0';
	return (i);
}
