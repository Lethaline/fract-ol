/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:21 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 12:04:22 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	mandelbrot(t_win *args, int x, int y, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < 80)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = tmp;
		n++;
	}
	if (x == 450 && y == 450)
		printf("%d\n", n);
	color(args, x, y, n);
}

void	mandeldraw(t_win *args)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = args->min_r + (double)x * (args->max_r - args->min_r) / WIDTH;
			ci = args->min_i + (double)y * (args->max_i - args->min_i) / HEIGHT;
			mandelbrot(args, x, y, cr, ci);
			x++;
		}
		y++;
	}
}
