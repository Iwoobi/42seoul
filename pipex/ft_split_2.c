/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:30:41 by youhan            #+#    #+#             */
/*   Updated: 2022/05/10 19:42:47 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	count_str_2(int *count, int *a)
{
	if (*a == 0)
		count[0] += 1;
	else
		count[1] += 1;
	*a = 1;
}
