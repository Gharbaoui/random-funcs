/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <mel-ghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:53:20 by mel-ghar          #+#    #+#             */
/*   Updated: 2019/11/13 23:28:34 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct
{
	int		sign;
	int		zero;
	int		width;
	int		perc;
	char	flag;
}			t_info;

int			ft_printf(const char *str, ...);
void		ft_putchar(char c);
void		default_info(t_info *inf);
void		fill_info(const char **str, t_info *inf, va_list args);
int			handel_zero(const char **str, va_list args);
int			non_point(const char *str);
void		help_with_zero(t_info *inf);
int			check_sign(const char **str);
int			handel_num_star(const char **str, va_list args, int *sign);
int			is_digit(char c);
void		work_with_info(t_info *inf, va_list args, int *sign);
int			handel_str(t_info *inf, va_list args);
char		*ft_strdup(char *str);
void		*ft_calloc(int n);
char		*ft_substr(char *str, int start, int len, int n);
void		ft_putspace(int n);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
int			handel_dec(t_info *inf, va_list args);
char		*ft_itoi(long n, int zeros);
int			count_size_dec(long n, int perc);
int			handel_adress(t_info *inf, va_list args);
char		*adress_str(va_list args);
int			count_hex(unsigned long n);
char		handel_hex_char(int n, int upper);
int			handel_unsigned_int(t_info *inf, va_list args);
int			count_unsigned_int(unsigned int n);
int			handel_hex_x(t_info *inf, va_list args);
char		*hex_unsigned(va_list args, int upper, int perc);
int			handel_perc_char(t_info *inf, va_list args);
#endif
