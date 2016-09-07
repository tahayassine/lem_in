/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:51:47 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/27 23:53:10 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_lineprint(t_texts *text)
{
	ft_printf("\n\033[35m*******************TEXT********************\033[0m\n");
	while (text != NULL)
	{
		ft_printf("%s\n", text->line);
		text = text->next;
	}
	ft_printf("\033[35m********************************************\033[0m\n");
}

void	ft_errorandexit(int x)
{
	if (x == 0)
		printf("\033[31mERREUR: Wrong Ants Number\033[0m\n");
	else if (x == 1)
		printf("\033[31mERREUR: Wrong Room\033[0m\n");
	else if (x == 2)
		printf("\033[31mERREUR: Wrong Pipe\033[0m\n");
	else if (x == 6)
		printf("\033[31mERREUR: Impossible Map\033[0m\n");
	else if (x == 10)
		printf("\033[31mERREUR\033[0m\n");
	exit(0);
}
