/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unrelated.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:10:39 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 03:04:05 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	default_info(t_info *inf)
{
	inf->zero = -1;
	inf->sign = 0;
	inf->width = 0;
	inf->perc = -1;
	inf->flag = '\0';
}

int		is_digit(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int		non_point(const char *str)
{
	while (!(*str >= 'a' && *str <= 'z') && *str != 'X' && *str != '%')
	{
		if (*str == '.')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strdup(char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	if (!(tmp = ft_calloc(1 + ft_strlen(str))))
		return (NULL);
	while (str[++i])
		tmp[i] = str[i];
	return (tmp);
}
