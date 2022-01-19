/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:03:21 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/20 01:15:50 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_lux(t_format *fmt, t_store *st, char *base)
{
	unsigned int	c;
	char			*s;

	c = va_arg(fmt->ap, unsigned int);
	s = ft_itoa_base(c, base);
	st->argument = ft_strdup(s);
	if (!st->argument)
		return ;
	free(s);
	if (st->precision > -1)
	{
		if (st->precision == 0 && c == 0)
		{
			free(st->argument);
			st->argument = ft_strdup("");
			if (!st->argument)
				return ;
		}
		ft_add_left(&st->argument, '0', st->precision);
		st->padding = ' ';
	}
	ft_convert_lux_next(st, c);
}

void	ft_convert_lux_next(t_store *st, unsigned int c)
{
	if ((ft_strchr(st->prefix, '#') && st->type != 'u') && c != 0)
		ft_convert_lux_next_prefix(st);
	else
	{
		if (st->left_alignment)
			ft_add_right(&st->argument, ' ', st->width);
		else
			ft_add_left(&st->argument, st->padding, st->width);
	}
	st->len = ft_strlen(st->argument);
}

void	ft_convert_lux_next_prefix(t_store *st)
{
	if (st->left_alignment)
	{
		ft_add_prefix_x(st);
		ft_add_right(&st->argument, ' ', st->width);
	}
	else
	{
		if (st->padding == '0')
		{
			ft_add_left(&st->argument, st->padding, st->width - 2);
			ft_add_prefix_x(st);
		}
		else
		{
			ft_add_prefix_x(st);
			ft_add_left(&st->argument, st->padding, st->width);
		}
	}
}
