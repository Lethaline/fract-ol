/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:29:41 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:26:49 by lolemmen         ###   ########.fr       */
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
	return ;
}
