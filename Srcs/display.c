/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 22:31:16 by lolemmen          #+#    #+#             */
/*   Updated: 2022/06/27 14:36:45 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	display_values(t_win *args)
{
	printf("min_r : %f\n", args->min_r);
	printf("max_r : %f\n", args->max_r);
	printf("min_i : %f\n", args->min_i);
	printf("max_i : %f\n", args->max_i);
	printf("con_r : %f\n", args->const_r);
	printf("con_i : %f\n", args->const_i);
	printf("mou_x : %d\n", args->mouse_x);
	printf("mou_y : %d\n", args->mouse_y);
	printf("type  : %d\n", args->type);
}

void	ft_put_text_on_screen(t_win *args)
{
	(void)args;
}
