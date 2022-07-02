/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:13:45 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 12:12:54 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void    ft_clean_values(t_win *args)
{
    args->mlx = NULL;
    args->win = NULL;
    args->img = NULL;
    args->img_ptr = NULL;
    args->min_r = 0;
    args->max_r = 0;
    args->min_i = 0;
    args->max_i = 0;
    args->const_r = -1;
    args->const_i = -1;
    args->cr = 0;
    args->ci = 0;
    args->mouse_x = 0;
    args->mouse_y = 0;
    args->x = 0;
    args->y = 0;
    args->color = 0;
    args->type = 0;
}

void    ft_clean_close(t_win *args)
{
    ft_clean_values(args);
    exit(1);
}