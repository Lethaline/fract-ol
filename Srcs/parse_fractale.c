/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:29:41 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 12:01:12 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_parse_fractale(t_win *args)
{
	if (args->type == 1)
		mandelbrot(args);
	else if (args->type == 2)
		julia(args);
	else if (args->type == 3)
		burningship(args);
	else if (args->type == 4)
		tricorn(args);
	ft_init_fractol_limits(args);
	return ;
}
