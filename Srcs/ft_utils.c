/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolemmen <lolemmen@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:06:52 by lolemmen          #+#    #+#             */
/*   Updated: 2022/07/22 18:12:01 by lolemmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

static double	ft_atof2(char *str, int i)
{
	double	nb;
	int		afterdot;
	int		dot;

	afterdot = 0;
	dot = 0;
	nb = 0;
	while (((str[i] >= 48 && str[i] <= 57) || str[i] == 46) && str[i])
	{
		if (str[i] == 46 && dot == 1)
			break ;
		if (str[i] == 46 && dot == 0)
			dot = 1;
		if (str[i] != 46)
			nb = nb * 10.0 + (str[i] - 48);
		if (str[i] >= 48 && str[i] <= 57 && dot == 1)
			afterdot++;
		i++;
	}
	while (afterdot > 0)
	{
		nb *= 0.1;
		afterdot--;
	}
	return (nb);
}

double	ft_atof(char *str)
{
	int	minus;
	int	i;

	minus = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	return (ft_atof2(str, i) * minus);
}
