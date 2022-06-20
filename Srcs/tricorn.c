/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:13 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 17:40:49 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	tricorn(t_win *args, int x, int y, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = cr;
	zi = ci;
	while (n < 1000)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = tmp;
		n++;
	}
	color(args, x, y, n);
}

void	tridraw(t_win *args)
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
			tricorn(args, x, y, cr, ci);
			x++;
		}
		y++;
	}
}
