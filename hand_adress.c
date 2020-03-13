/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_adress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 02:15:48 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:41 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handel_adress(t_info *inf, va_list args)
{
	char	*str;
	int		len;
	int		spaces;

	str = adress_str(args);
	if (str[2] == '0' && inf->zero != -2 && inf->perc == 0)
		str[2] = '\0';
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

int		count_hex(unsigned long n)
{
	int re;

	re = 1;
	while (n /= 16)
		re++;
	return (re);
}

char	*adress_str(va_list args)
{
	unsigned long	num;
	int				size;
	char			*str;

	num = va_arg(args, unsigned long);
	size = count_hex(num) + 2;
	if (!(str = ft_calloc(size + 1)))
		return (NULL);
	while (num || size == 3)
	{
		str[--size] = handel_hex_char((num % 16), 0);
		num /= 16;
	}
	str[0] = '0';
	str[1] = 'x';
	return (str);
}

char	handel_hex_char(int n, int upper)
{
	return (n > 9 ? ('a' + (n - 10) - upper) : (n + '0'));
}
