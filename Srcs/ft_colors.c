/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/25 16:05:04 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_color(t_win *f, int n)
{
	int	color;

	if (n >= 0 && n <= MAX_ITERATIONS - 1)
		color = f->color * n;
	else
		color = 0x000000;
	f->img_ptr[f->x * 4 + f->y * WIDTH * 4] = color;
	f->img_ptr[f->x * 4 + f->y * WIDTH * 4 + 1] = color >> 8;
	f->img_ptr[f->x * 4 + f->y * WIDTH * 4 + 2] = color >> 16;
	f->img_ptr[f->x * 4 + f->y * WIDTH * 4 + 3] = color >> 24;
}

void	ft_set_colors(t_win *f, int color)
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
		f->colors[i] = 0;
		rgb[0] -= i % 0xFF;
		rgb[1] -= i % 0xFF;
		rgb[2] -= i % 0xFF;
		f->colors[i] = 0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2];
	}
	f->colors[MAX_ITERATIONS - 1] = 0;
}
