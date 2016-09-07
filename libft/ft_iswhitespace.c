/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 01:30:58 by tyassine          #+#    #+#             */
/*   Updated: 2015/12/05 17:02:34 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhitespace(int c)
{
	int res;

	res = 0;
	if (c == ' ' || c == '\n' || c == '\t')
		res = 1;
	return (res);
}
