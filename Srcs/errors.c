/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:12:03 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/02 11:36:28 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

void    ft_error_message(char *message, int close, t_win *args)
{
    ft_putendl(message);
    if (close == 1)
        ft_clean_close(args);
}