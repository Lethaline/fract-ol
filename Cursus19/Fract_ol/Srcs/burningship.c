/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:18 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 14:26:14 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	burningship(t_win *args, int x, int y, double cr, double ci)
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
		if ((zr * zr + zi * zi) > 10.0)
			break ;
		zr = fabs(zr);
		zi = fabs(zi);
		tmp = 2 * zr * zi + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = tmp;
		n++;
	}
	color(args, x, y, n);
}

void	burningdraw(t_win *args)
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
			burningship(args, x, y, cr, ci);
			x++;
		}
		y++;
	}
}
