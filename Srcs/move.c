/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:34:13 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 15:37:53 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	move_arrow(t_win *args, int keycode)
{
	double center_r;
	double center_i;

	center_r = args->max_r - args->min_r;
	center_i = args->max_i - args->min_i;
	if (keycode == 123)
	{
		args->min_r -= center_r * 0.2;
		args->max_r -= center_r * 0.2;
	}
	else if (keycode == 124)
	{
		args->min_r += center_r * 0.2;
		args->max_r += center_r * 0.2;
	}
	else if (keycode == 126)
	{
		args->min_i -= center_i * 0.2;
		args->max_i -= center_i * 0.2;
	}
	else
	{
		args->min_i += center_i * 0.2;
		args->max_i += center_i * 0.2;
	}
	ft_draw(args);
}
