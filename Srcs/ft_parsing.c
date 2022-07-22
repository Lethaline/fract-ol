/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:00:26 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/22 18:11:51 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_parsing(t_win *f, char **av)
{
	char	*type;

	type = ft_strlowcase(av[1]);
	if (ft_strcmp(type, "mandelbrot") == 0)
		f->type = 1;
	else if (ft_strcmp(type, "julia") == 0)
	{
		f->type = 2;
		if (av[2] && av[3])
		{
			f->const_r = ft_atof(av[2]);
			f->const_i = ft_atof(av[3]);
		}
	}
	else if (ft_strcmp(type, "burningship") == 0)
		f->type = 3;
	else
		ft_error_message("Error : Invalid Argument.", 1, f);
	ft_init_fractol_limits(f);
}

void	ft_parse_fractale(t_win *f)
{
	if (f->type == 1)
		ft_mandelbrot(f);
	else if (f->type == 2)
		ft_julia(f);
	else if (f->type == 3)
		ft_burningship(f);
	return ;
}
