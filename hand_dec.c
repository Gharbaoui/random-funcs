/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 01:32:23 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:29 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handel_dec(t_info *inf, va_list args)
{
	char	*str;
	int		spaces;
	int		len;
	long	n;

	n = (long)va_arg(args, int);
	if (n == 0 && inf->perc == 0 && inf->zero != -2)
		str = ft_strdup("");
	else if (inf->zero == -2 && n < 0)
		str = ft_itoi(n, inf->perc - 1);
	else
		str = ft_itoi(n, inf->perc);
	spaces = inf->width - ft_strlen(str);
	len = (spaces > 0 ? spaces + ft_strlen(str) : ft_strlen(str));
	if (inf->sign > 0)
		ft_putspace(spaces);
	ft_putstr(str);
	free(str);
	if (inf->sign < 0)
		ft_putspace(spaces);
	return (len);
}

char	*ft_itoi(long n, int zeros)
{
	char	*str;
	int		size;
	long	num;

	num = (long)n;
	size = count_size_dec(n, zeros);
	if (n < 0)
	{
		size++;
		num *= -1;
	}
	if (!(str = ft_calloc(size + 1)))
		return (NULL);
	num *= 10;
	while ((num /= 10) || size)
		str[size-- - 1] = (num % 10) + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

int		count_size_dec(long n, int perc)
{
	int re;

	re = 1;
	perc = (perc < 0 ? 0 : perc);
	while (n /= 10)
		re++;
	if (perc > re)
		return (perc);
	return (re);
}
