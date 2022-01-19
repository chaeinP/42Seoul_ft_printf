/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:49:56 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/20 00:36:25 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(t_format *fmt, t_store *st)
{
	void	*ptr;
	char	*s;

	ptr = va_arg(fmt->ap, void *);
	s = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	st->argument = s;
	if (st->precision > -1)
	{
		if (st->precision == 0 && !ptr)
		{
			free(st->argument);
			st->argument = ft_strdup("");
			if (!st->argument)
				return ;
		}
		ft_add_left(&st->argument, '0', st->precision);
		st->padding = ' ';
		ft_add_prefix_x(st);
	}
	else if (st->padding != '0' || st->left_alignment)
		ft_add_prefix_x(st);
	ft_convert_p_next(st);
}

void	ft_convert_p_next(t_store *st)
{
	if (st->left_alignment)
		ft_add_right(&st->argument, ' ', st->width);
	else
	{
		if (st->padding == '0')
		{
			ft_add_left(&st->argument, st->padding, st->width - 2);
			ft_add_prefix_x(st);
		}
		else
			ft_add_left(&st->argument, st->padding, st->width);
	}
	st->len = ft_strlen(st->argument);
}
