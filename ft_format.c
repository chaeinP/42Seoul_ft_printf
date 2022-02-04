/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:07:12 by chaepark          #+#    #+#             */
/*   Updated: 2022/02/04 23:00:20 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_format(t_format *fmt, t_store *st)
{
	ft_flags(fmt, st);
	ft_width(fmt, st);
	ft_precision(fmt, st);
	ft_type(fmt, st);
	if (ft_strchr("-0# +123456789*.", fmt->format[fmt->i]) \
		&& st->type == '\0')
		ft_format(fmt, st);
	return (st);
}

void	ft_flags(t_format *fmt, t_store *st)
{
	char	*tmp;
	char	c;

	while (ft_strchr("-+ 0#", fmt->format[fmt->i]))
	{
		c = fmt->format[fmt->i];
		if (c == '-')
			st->left_alignment = 1;
		else if (ft_strchr(" +#", c))
		{
			tmp = st->prefix;
			st->prefix = ft_strjoinchr(tmp, c);
			if (!st->prefix)
				return ;
			free(tmp);
		}
		else if (c == '0')
			st->padding = '0';
		fmt->i++;
	}
}

void	ft_width(t_format *fmt, t_store *st)
{
	int		width;
	char	c;

	width = 0;
	c = fmt->format[fmt->i];
	if (c == '*')
	{
		width = va_arg(fmt->ap, int);
		if (width < 0)
		{
			st->left_alignment = 1;
			width *= -1;
		}
		fmt->i++;
	}
	else if (ft_isdigit(c))
	{
		while (ft_isdigit(fmt->format[fmt->i]))
			width = (width * 10) + (fmt->format[fmt->i++] - '0');
	}
	st->width = width;
}

void	ft_precision(t_format *fmt, t_store *st)
{
	int		precision;
	char	c;

	precision = 0;
	if (fmt->format[fmt->i] == '.')
	{
		fmt->i++;
		c = fmt->format[fmt->i];
		if (c == '*')
		{
			precision = va_arg(fmt->ap, int);
			fmt->i++;
		}
		else if (ft_isdigit(c))
		{
			precision = 0;
			while (ft_isdigit(fmt->format[fmt->i]))
				precision = (precision * 10) + (fmt->format[fmt->i++] - '0');
		}
		else
			precision = 0;
	}
	st->precision = precision;
}

void	ft_type(t_format *fmt, t_store *st)
{
	if (ft_strchr("cspdiuxX%", fmt->format[fmt->i]))
		st->type = fmt->format[fmt->i++];
}
