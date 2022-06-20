/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:58:47 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 18:03:57 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	test(t_win *args, int x, int y, double cr, double ci)
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
		tmp = 3 * (zr * zr * zi) * (zi * zi * zr) + ci;
		zr = (zr * zr * zr) - (zi * zi * zi) + cr;
		zi = tmp;
		n++;
	}
	color(args, x, y, n);
}

void	testdraw(t_win *args)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < HEIGHT)
		{
			cr = args->min_r + (double)x * (args->max_r - args->min_r) / WIDTH;
			ci = args->min_i + (double)y * (args->max_i - args->min_i) / HEIGHT;
			test(args, x, y, cr, ci);
			x++;
		}
		y++;
	}
}
