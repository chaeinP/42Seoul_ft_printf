/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaepark <chaepark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:49:00 by chaepark          #+#    #+#             */
/*   Updated: 2022/01/20 00:57:49 by chaepark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_format
{
	const char	*format;
	va_list		ap;
	size_t		i;
	size_t		len;
}				t_format;

typedef struct s_store
{
	int		left_alignment;
	char	*prefix;
	char	padding;
	int		width;
	int		precision;
	char	type;
	char	*argument;
	size_t	len;
}				t_store;

//ft_printf.c
int			ft_printf(const char *format, ...);
void		ft_print_in_conditions(t_format *fmt);

//ft_initialize.c
t_format	*ft_initialize_fmt(const char *format, va_list ap);
t_store		*ft_initialize_store(void);

//ft_format.c
void		*ft_format(t_format *fmt, t_store *st);
void		ft_flags(t_format *fmt, t_store *st);
void		ft_width(t_format *fmt, t_store *st);
void		ft_precision(t_format *fmt, t_store *st);
void		ft_type(t_format *fmt, t_store *st);

//ft_conversion.c
void		ft_type_conversion(t_format *fmt, t_store *st);

//ft_convert_di.c
void		ft_convert_di(t_format *fmt, t_store *st);
void		ft_convert_di_next(t_store *st, int sign);

//ft_convert_c.c
void		ft_convert_c(t_format *fmt, t_store *st);

//ft_convert_s.c
void		ft_convert_s(t_format *fmt, t_store *st);

//ft_convert_p.c
void		ft_convert_p(t_format *fmt, t_store *st);
void		ft_convert_p_next(t_store *st);

//ft_convert_x.c
void		ft_convert_lux(t_format *fmt, t_store *st, char *base);
void		ft_convert_lux_next(t_store *st, unsigned int c);
void		ft_convert_lux_next_prefix(t_store *st);

//ft_convert_X.c
void		ft_convert_pct(t_store *st);

//ft_add.c
void		ft_add_left(char **arg, char pad, int width);
void		ft_add_right(char **arg, char pad, int width);
void		ft_add_prefix(t_store *st, int sign);
void		ft_add_prefix_x(t_store *st);
#endif
