/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:57:50 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:23 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_with_info(t_info *inf, va_list args, int *len)
{
	if (inf->flag == 's')
		*len += handel_str(inf, args);
	else if (inf->flag == 'd' || inf->flag == 'i')
		*len += handel_dec(inf, args);
	else if (inf->flag == 'p')
		*len += handel_adress(inf, args);
	else if (inf->flag == 'u')
		*len += handel_unsigned_int(inf, args);
	else if (inf->flag == 'x' || inf->flag == 'X')
		*len += handel_hex_x(inf, args);
	else if (inf->flag == '%' || inf->flag == 'c')
		*len += handel_perc_char(inf, args);
}
