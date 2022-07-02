/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:04:14 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 13:30:57 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_draw(t_win *args)
{
	args->y = 0;
	while (args->y < HEIGHT)
	{
		args->x = 0;
		while (args->x < WIDTH)
		{
			args->cr = args->min_r + args->x * (args->max_r - args->min_r) / WIDTH;
			args->ci = args->min_i + args->y * (args->max_i - args->min_i) / HEIGHT;
			ft_parse_fractale(args);
			args->x++;
		}
		args->y++;
	}
	mlx_put_image_to_window(args->mlx, args->win, args->img, 0, 0);
}
