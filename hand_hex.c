/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 02:34:27 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:26 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handel_hex_x(t_info *inf, va_list args)
{
	char	*str;
	int		spaces;
	int		len;
	int		length;

	if (inf->flag == 'X')
		str = hex_unsigned(args, 32, inf->perc);
	else
		str = hex_unsigned(args, 0, inf->perc);
	if (*str == '0' && inf->perc == 0 && inf->zero != -2)
		*str = '\0';
	length = ft_strlen(str);
	spaces = inf->width - length;
	len = (spaces > 0 ? spaces + length : length);
	if (inf->sign > 0)
		ft_putspace(spaces);
	ft_putstr(str);
	free(str);
	if (inf->sign < 0)
		ft_putspace(spaces);
	return (len);
}

char	*hex_unsigned(va_list args, int upper, int perc)
{
	int				size;
	char			*str;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	size = count_hex((long)n);
	if (perc > size)
		size += (perc - size);
	if (!(str = ft_calloc(size + 1)))
		return (NULL);
	while (n || size == 1 || size)
	{
		str[--size] = handel_hex_char((n % 16), upper);
		n /= 16;
	}
	return (str);
}
