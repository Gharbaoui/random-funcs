/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 02:28:11 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:21 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			handel_unsigned_int(t_info *inf, va_list args)
{
	char	*str;
	int		len;
	int		spaces;
	int		length;
	long	n;

	n = (long)va_arg(args, unsigned int);
	if (inf->perc == 0 && inf->zero != -2 && !n)
		str = ft_strdup("");
	else
		str = ft_itoi(n, inf->perc);
	length = ft_strlen(str);
	spaces = inf->width - length;
	len = (spaces > 0 ? spaces + length : length);
	if (inf->sign > 0)
		ft_putspace(spaces);
	ft_putstr(str);
	if (inf->sign < 0)
		ft_putspace(spaces);
	free(str);
	return (len);
}

int			count_unsigned(unsigned int n)
{
	int re;

	re = 1;
	while (n /= 10)
		re++;
	return (re);
}
