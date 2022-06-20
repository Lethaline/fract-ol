/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:01:14 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/19 18:29:45 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

/*static void	zoom(t_win *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}*/

int	mouse_hook(int keycode, t_win *args)
{
	(void)*args;
	printf("%d\n", keycode);
	return (0);
}
