/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:26:33 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/17 16:09:25 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_initialize_fmt(const char *format, va_list ap)
{
	t_format	*fmt;

	fmt = malloc(sizeof(t_format));
	if (!fmt)
		return (0);
	fmt->format = format;
	va_copy(fmt->ap, ap);
	fmt->i = 0;
	fmt->len = 0;
	return (fmt);
}

t_store	*ft_initialize_store(void)
{
	t_store	*st;

	st = malloc(sizeof(t_store));
	if (!st)
		return (0);
	st->left_alignment = 0;
	st->prefix = ft_strdup("");
	st->padding = ' ';
	st->width = 0;
	st->precision = -1;
	st->type = '\0';
	st->argument = NULL;
	st->len = 0;
	return (st);
}
