/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:56:45 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:22:41 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	reset(t_win *args)
{
	args->min_r = -2.0;
	args->max_r = 1.0;
	args->min_i = -1.5;
	args->max_i = args->min_i + (args->max_r - args->min_r) * HEIGHT / WIDTH;
	mlx_clear_window(args->mlx, args->win);
	ft_draw(args);
}
