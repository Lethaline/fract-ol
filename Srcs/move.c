/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:34:13 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/09 15:35:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	move_arrow(t_win *args, double segment, int keycode)
{
	double center_r;
	double center_i;

	center_r = args->max_r - args->min_r;
	center_i = args->max_i - args->min_i;
	if (keycode == 123)
	{
		args->min_r -= center_r * segment;
		args->max_r -= center_r * segment;
	}
	else if (keycode == 124)
	{
		args->min_r += center_r * segment;
		args->max_r += center_r * segment;
	}
	else if (keycode == 126)
	{
		args->min_i -= center_i * segment;
		args->max_i -= center_i * segment;
	}
	else
	{
		args->min_i += center_i * segment;
		args->max_i += center_i * segment;
	}
	ft_draw(args);
}
