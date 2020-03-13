/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:51:33 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/14 04:48:31 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_info		inf;
	int			len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%' || *(++str) == '%')
		{
			ft_putchar(*str);
			len++;
		}
		else
		{
			fill_info(&str, &inf, args);
			work_with_info(&inf, args, &len);
		}
		str++;
	}
	va_end(args);
	return (len);
}
