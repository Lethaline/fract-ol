/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:05:13 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 14:33:43 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	tricorn(t_win *args)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	n = 0;
	zr = args->cr;
	zi = args->ci;
	while (n < 1000)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + args->ci;
		zr = (zr * zr) - (zi * zi) + args->cr;
		zi = tmp;
		n++;
	}
	color(args, n);
}
