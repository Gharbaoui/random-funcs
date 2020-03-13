/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unrelated1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:57:52 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:31 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(int n)
{
	char	*tmp;

	if (!(tmp = malloc(n)))
		return (NULL);
	tmp[--n] = '\0';
	return (tmp);
}

char	*ft_substr(char *str, int start, int len, int n)
{
	int		i;
	char	*ptr;

	i = -1;
	len = (len < 0 || len > ft_strlen(str) ? ft_strlen(str) : len);
	if (!(ptr = ft_calloc(len + 1)))
		return (NULL);
	while (++i < len)
		ptr[i] = str[i + start];
	if (n)
		free(str);
	return (ptr);
}

int		ft_strlen(char *str)
{
	return (*str ? ft_strlen(++str) + 1 : 0);
}

void	ft_putspace(int n)
{
	if (n > 0)
		while (n--)
			ft_putchar(' ');
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
