/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:59:05 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 15:07:03 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

static void	zoom(t_win *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

int	key_hook(int keycode, t_win *args)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == LEFT || keycode == RIGHT || keycode == BOTTOM || keycode == TOP)
		move_arrow(args, keycode);
	else if (keycode == 43)
		zoom(args, 0.5);
	else if (keycode == 47)
		zoom(args, 2.0);
	else if (keycode == SPACE)
		reset(args);
	printf("%d : %f\n", keycode, args->min_r);
	return (0);
}
