/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:14:44 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 13:03:50 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_format	*fmt;
	int			len;
	va_list		ap;

	if (!format)
		return (0);
	va_start(ap, format);
	fmt = ft_initialize_fmt(format, ap);
	if (!fmt)
		return (0);
	while (fmt->format[fmt->i])
	{
		if (fmt->format[fmt->i] == '%')
		{
			fmt->i++;
			ft_print_in_conditions(fmt);
		}
		else
			fmt->len += write(1, &fmt->format[fmt->i++], 1);
	}
	len = fmt->len;
	free(fmt);
	return (len);
}

void	ft_print_in_conditions(t_format *fmt)
{
	t_store	*st;

	st = ft_initialize_store();
	ft_format(fmt, st);
	if (st->type)
	{
		ft_type_conversion(fmt, st);
		fmt->len += write(1, st->argument, st->len);
		free(st->argument);
	}
	free(st->prefix);
	free(st);
}
