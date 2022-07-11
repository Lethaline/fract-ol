/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:38:46 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/06 14:01:32 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

t_win    ft_init_fractal(void)
{
    t_win   args;

    args.mlx = mlx_init();
    args.win = mlx_new_window(args.mlx, WIDTH, HEIGHT, "Fract-ol by Lolemmen");
    args.min_r = 0;
    args.max_r = 0;
    args.min_i = 0;
    args.max_i = 0;
    args.const_r = 0.3; // 0.183333, 0.096667, -0.766667, 0.3, -0.1011
	args.const_i = 0.5; // 0.596667, -0.613333, -0.090000, 0.5, 0.9563
    args.color = 0xABCDEF;
    args.colors = (int *)malloc(sizeof(int) * MAX_ITERATIONS + 1);
    if (!args.colors)
        ft_error_message("Error : Malloc", 1, &args);
    ft_set_colors(&args, args.color);
    args.type = 0;
    return (args);
}

void    ft_init_img(t_win *args)
{
    int     endian;
    int     bits_by_pixel;
    int     size_line;
    char    *buffer;

    args->img = mlx_new_image(args->mlx, WIDTH, HEIGHT);
    buffer = mlx_get_data_addr(args->img, &bits_by_pixel, &size_line, &endian);
    args->img_ptr = buffer;
}

void    ft_init_fractol_limits(t_win *args)
{
    if (args->type == JULIA)
    {
        args->min_r = -2.0;
        args->max_r = 2.0;
        args->min_i = -2.0;
        args->max_i = args->min_i + (args->max_r - args->min_r) * HEIGHT / WIDTH;
    }
    else
    {
        args->min_r = -2.0;
        args->max_r = 1.0;
        args->min_i = -1.5;
        args->max_i = args->min_i + (args->max_r - args->min_r) * HEIGHT / WIDTH;
    }
}
