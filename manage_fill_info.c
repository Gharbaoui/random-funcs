/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fill_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:21:56 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:32:06 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_info(const char **str, t_info *inf, va_list args)
{
	int a;

	a = -9;
	default_info(inf);
	if (**str == '0' && non_point(*str))
	{
		inf->perc = handel_zero(str, args);
		if (inf->perc < 0)
			help_with_zero(inf);
		inf->zero = -2;
	}
	else
	{
		inf->sign = check_sign(str);
		inf->width = handel_num_star(str, args, &inf->sign);
		if (**str == '.')
		{
			(*str)++;
			inf->perc = 0;
		}
		if (**str == '*' || is_digit(**str))
			inf->perc = handel_num_star(str, args, &a);
	}
	inf->flag = **str;
}

int		handel_zero(const char **str, va_list args)
{
	int re;

	re = 0;
	while (**str && is_digit(**str))
		re = (re * 10) + (*(*str)++ - '0');
	if (**str == '*')
	{
		re = va_arg(args, int);
		(*str)++;
	}
	return (re);
}

void	help_with_zero(t_info *inf)
{
	inf->width = -(inf->perc);
	inf->sign = -1;
	inf->perc = -1;
}

int		check_sign(const char **str)
{
	int re;

	re = 1;
	while (**str == '-')
	{
		re = -1;
		(*str)++;
	}
	return (re);
}

int		handel_num_star(const char **str, va_list args, int *sign)
{
	int a;
	int re;

	re = 0;
	if (**str == '*')
	{
		(*str)++;
		a = (int)va_arg(args, int);
		if (*sign == -9)
			return (a);
		if (a < 0)
			*sign = -1;
		return (a < 0 ? -a : a);
	}
	while (**str && is_digit(**str))
		re = (re * 10) + (*(*str)++ - '0');
	return (re);
}
