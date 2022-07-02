/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 13:30:06 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	color(t_win *args, int color)
{
	args->img_ptr[args->x * 4 + args->y * WIDTH * 4] = color;
	args->img_ptr[args->x * 4 + args->y * WIDTH * 4 + 1] = color >> 8;
	args->img_ptr[args->x * 4 + args->y * WIDTH * 4 + 2] = color >> 16;
	args->img_ptr[args->x * 4 + args->y * WIDTH * 4 + 3] = color >> 24;
}

void	ft_set_colors(t_win *args, int color)
{
	int	i;
	int	rgb[3];

	rgb[0] = (color >> 16) & 0xFF;
	rgb[1] = (color >> 8) & 0xFF;
	rgb[2] = (color >> 0) & 0xFF;
	i = -1;
	while (rgb[0] < 0x33 || rgb[1] < 0x33 || rgb[2] < 0x33)
	{
		if (rgb[0] != 0xFF)
			rgb[0]++;
		if (rgb[1] != 0xFF)
			rgb[1]++;
		if (rgb[2] != 0xFF)
			rgb[2]++;
	}
	while (++i < MAX_ITERATIONS)
	{
		args->colors[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i % 0xFF;
		args->colors[i] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	args->colors[MAX_ITERATIONS - 1] = 0;
}