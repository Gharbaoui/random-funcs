/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:46:29 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:38 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handel_str(t_info *inf, va_list args)
{
	int		len;
	int		spaces;
	char	*str;
	char	*tmp;

	tmp = va_arg(args, char *);
	if (!tmp)
		str = ft_substr(ft_strdup("(null)"), 0, inf->perc, 1);
	else
		str = ft_substr(tmp, 0, inf->perc, 0);
	len = ft_strlen(str);
	spaces = inf->width - len;
	len = (spaces > 0 ? len + spaces : len);
	if (inf->sign > 0)
		ft_putspace(spaces);
	ft_putstr(str);
	if (inf->sign < 0)
		ft_putspace(spaces);
	free(str);
	return (len);
}

int		handel_perc_char(t_info *inf, va_list args)
{
	int		n;
	char	c;

	if (inf->flag != '%')
		c = va_arg(args, int);
	else
		c = '%';
	n = inf->perc - 1;
	if (inf->sign > 0)
		ft_putspace(inf->width - 1);
	while (n-- > 0 && inf->zero == -2)
		ft_putchar('0');
	ft_putchar(c);
	if (inf->sign < 0)
		ft_putspace(inf->width - 1);
	return (inf->width > 0 ? inf->width : 1);
}
