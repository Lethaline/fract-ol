/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/21 22:01:58 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void	ft_error_message(char *message, int close, t_win *f)
{
	ft_putendl(message);
	ft_display_available();
	if (close == 1)
		ft_clean_close(f);
}
