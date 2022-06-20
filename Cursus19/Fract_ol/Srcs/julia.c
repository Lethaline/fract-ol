/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:23 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 18:14:48 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	julia(t_win *args, int x, int y, double cr, double ci)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < 1000)
	{
		if ((cr * cr + ci * ci) > 4.0)
			break ;
		tmp = 2 * cr * ci + args->const_i;
		cr = (cr * cr) - (ci * ci) + args->const_r;
		ci = tmp;
		n++;
	}
	color(args, x, y, n);
}

void	juliadraw(t_win *args)
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
			julia(args, x, y, cr, ci);
			x++;
		}
		y++;
	}
}
