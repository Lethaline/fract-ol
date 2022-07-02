/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:34:13 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:22:49 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	move_arrow(t_win *args, int keycode)
{
	if (keycode == 123)
	{
		args->min_r -= (args->max_r - args->min_r) * 0.2;
		args->max_r -= (args->max_r - args->min_r) * 0.2;
	}
	else if (keycode == 124)
	{
		args->min_r += (args->max_r - args->min_r) * 0.2;
		args->max_r += (args->max_r - args->min_r) * 0.2;
	}
	else if (keycode == 126)
	{
		args->min_i -= (args->max_i - args->min_i) * 0.2;
		args->max_i -= (args->max_i - args->min_i) * 0.2;
	}
	else
	{
		args->min_i += (args->max_i - args->min_i) * 0.2;
		args->max_i += (args->max_i - args->min_i) * 0.2;
	}
	mlx_clear_window(args->mlx, args->win);
	ft_draw(args);
}
