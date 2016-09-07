/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:51:07 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/27 23:54:19 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_freeanthill(t_anthill *anthill)
{
	t_room	*tmp;

	tmp = anthill->start;
	while (tmp->next[0])
	{
		anthill->start = tmp;
		tmp = tmp->next[0];
		free(anthill->start);
	}
}

void	ft_freequeue(t_queue *queue)
{
	t_queue	*tmp;

	tmp = queue;
	while (tmp->next)
	{
		queue = tmp;
		tmp = tmp->next;
		free(queue);
	}
}

void	ft_freeenv(t_param *env)
{
	t_tube	*tmp;

	tmp = env->tub;
	while (tmp->next)
	{
		env->tub = tmp;
		tmp = tmp->next;
		free(env->tub);
	}
}
