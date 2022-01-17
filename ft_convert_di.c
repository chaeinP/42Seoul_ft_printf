/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:25:35 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 17:28:52 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// line28: precision은 0보다 크고, arg가 0이면 precision만큼 0으로 왼쪽패딩 채우면 됨
// line28: precision 0, ary 0이면 아무것도 출력되지 않음, precision이 1이어야 0이 나옴
void	ft_convert_di(t_format *fmt, t_store *st)
{
	int	arg;
	int	sign;

	sign = 1;
	arg = (int)va_arg(fmt->ap, int);
	if (arg < 0)
		sign = -1;
	st->argument = ft_itoa(arg);
	if (st->precision > -1)
	{
		if (st->precision == 0 && arg == 0)
			st->argument = ft_strdup("");
		ft_add_left(&st->argument, '0', st->precision);
	}
	ft_convert_di_next(st, sign);
	st->len = ft_strlen(st->argument);
}

//정수는 오른쪽 패딩 값으로 0이 올 수 없다.
void	ft_convert_di_next(t_store *st, int sign)
{
	if (st->left_alignment)
	{
		ft_add_prefix(st, sign);
		ft_add_right(&st->argument, ' ', st->width);
	}
	else
	{
		if (st->padding == ' ')
		{
			ft_add_prefix(st, sign);
			ft_add_left(&st->argument, ' ', st->width);
		}
		else if (st->padding == '0')
		{
			if (sign < 0 || ft_strchr(st->prefix, ' ') || \
				ft_strchr(st->prefix, '+'))
				ft_add_left(&st->argument, '0', st->width - 1);
			else
				ft_add_left(&st->argument, '0', st->width);
			ft_add_prefix(st, sign);
		}
	}
}
