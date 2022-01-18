/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 23:28:09 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/18 00:20:38 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_pct(t_store *st)
{
	st->argument = ft_chrjoin("", st->type);
	st->len = ft_strlen(st->argument);
}
