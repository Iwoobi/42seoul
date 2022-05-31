/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youhan <youhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:58:56 by youhan            #+#    #+#             */
/*   Updated: 2022/05/27 20:58:58 by youhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	main(int argc, char **argv)
{
	t_list	*data;
	t_mlx	my_mlx;

	data = (t_list *)malloc(sizeof(t_list));
	if (data == NULL)
		return (-1);
	if (argc != 2)
		return (-1);
	if (open_file(argv[1], data) == -1)
		exit(1);
	inputdata_push(data);
	ft_fdf_init(data);
	my_mlx.data = data;
	ft_mlx_init(&my_mlx, 1000);
	mlx_hook(my_mlx.win, PRESS, 0, &deal_key, &my_mlx);
	mlx_hook(my_mlx.win, CLOSED, 0, &ft_close, &my_mlx);
	mlx_loop_hook(my_mlx.mlx, &main_loop, &my_mlx);
	mlx_loop(my_mlx.mlx);
}
