/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:18 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 13:25:26 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	burningship(t_win *args)
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
		tmp = fabs(2 * zr * zi) + args->ci;
		zr = (zr * zr) - (zi * zi) + args->cr;
		zi = tmp;
		n++;
	}
	color(args, args->colors[n]);
}
