/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_lux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:03:21 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/18 16:12:55 by chaepark         ###   ########.fr       */
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
	free(s);
	if (st->precision > -1)
	{
		if (st->precision == 0 && c == 0)
		{
			free(st->argument);
			st->argument = ft_strdup("");
		}
		ft_add_left(&st->argument, '0', st->precision);
		st->padding = ' ';
	}
	if (st->prefix && c != 0)
		ft_add_prefix_x(st);
	if (st->left_alignment)
		ft_add_right(&st->argument, ' ', st->width);
	else
		ft_add_left(&st->argument, st->padding, st->width);
	st->len = ft_strlen(st->argument);
}
