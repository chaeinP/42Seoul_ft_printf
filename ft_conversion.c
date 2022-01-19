/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:03:58 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/19 13:46:07 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_conversion(t_format *fmt, t_store *st)
{
	char	type;

	type = st->type;
	if (type == 'c')
		ft_convert_c(fmt, st);
	else if (type == 's')
		ft_convert_s(fmt, st);
	else if (type == 'd' || type == 'i')
		ft_convert_di(fmt, st);
	else if (type == 'p')
		ft_convert_p(fmt, st);
	else if (type == 'u')
		ft_convert_lux(fmt, st, "0123456789");
	else if (type == 'x')
		ft_convert_lux(fmt, st, "0123456789abcdef");
	else if (type == 'X')
		ft_convert_lux(fmt, st, "0123456789ABCDEF");
	else if (type == '%')
		ft_convert_pct(st);
}
