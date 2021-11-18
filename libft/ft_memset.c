/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 12:05:36 by youhan            #+#    #+#             */
/*   Updated: 2021/11/18 12:05:36 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int a, unsigned int n)
{
	unsigned char	*dest;

	dest = str;
	while (n > 0)
	{
		*dest = a;
		dest++;
		n--;
	}
	return (str);
}