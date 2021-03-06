/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 10:14:02 by tyassine          #+#    #+#             */
/*   Updated: 2016/04/07 10:14:04 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	han_oct2(va_list *now, t_data *d, t_type *v, t_form *i)
{
	if (i->type == 3)
	{
		v->lo = (unsigned long int)va_arg(*now, unsigned long int);
		d->string = itoabaseo(i, (v->lo), 8);
	}
	else if (i->type == 4)
	{
		v->llu = (unsigned long long)va_arg(*now, unsigned long long);
		d->string = itoabaseo(i, (v->llu), 8);
	}
	else if (i->type == 5)
	{
		v->uim = (uintmax_t)va_arg(*now, uintmax_t);
		d->string = itoabaseo(i, (v->uim), 8);
	}
	else if (i->type == 6)
	{
		v->uim = (uintmax_t)va_arg(*now, uintmax_t);
		d->string = itoabaseo(i, (v->uim), 8);
	}
}

int		han_oct(va_list *now, t_data *d, t_type *v, t_form *i)
{
	int	ret;

	ret = 0;
	if (d->type == 'O')
		i->type = 3;
	if (i->type == 0)
	{
		v->o = va_arg(*now, unsigned int);
		d->string = itoabaseo(i, (v->o), 8);
	}
	else if (i->type == 2)
	{
		v->hh = (unsigned char)va_arg(*now, unsigned int);
		d->string = itoabaseo(i, (v->hh), 8);
	}
	else if (i->type == 1)
	{
		v->uh = (unsigned short)va_arg(*now, unsigned int);
		d->string = itoabaseo(i, (v->uh), 8);
	}
	han_oct2(now, d, v, i);
	ret = ft_strlen(d->string);
	ret = print_unsigned(i, d, ret);
	free(d->string);
	return (ret);
}
