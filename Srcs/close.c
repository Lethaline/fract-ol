/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:13:45 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/10 15:54:08 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_clean_values(t_win *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->img_ptr = NULL;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->const_r = -1;
	f->const_i = -1;
	f->cr = 0;
	f->ci = 0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->x = 0;
	f->y = 0;
	f->color = 0;
	f->type = 0;
}

void	ft_clean_close(t_win *f)
{
	ft_clean_values(f);
	exit(1);
}
