/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:51:32 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/27 23:53:06 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_initqueue(t_queue *queue)
{
	queue->next = NULL;
	queue->output = NULL;
	queue->ok = 0;
}

t_room	*ft_initroom(t_room *room)
{
	int i;

	i = 0;
	if ((room = (t_room *)malloc(sizeof(t_room))) != NULL)
	{
		room->name = NULL;
		room->x = 0;
		room->y = 0;
		room->flag = 0;
		room->fils = 0;
		while (i <= 300)
		{
			room->prev[i] = NULL;
			room->next[i] = NULL;
			i++;
		}
		return (room);
	}
	return (NULL);
}

void	ft_initialanthill(t_anthill *anthill)
{
	anthill->start = NULL;
	anthill->end = NULL;
}

void	ft_initialenv(t_param *env)
{
	env->antsnbr = 0;
	env->start = 0;
	env->end = 0;
	env->tab = NULL;
	env->tub = NULL;
	if ((env->txt = (t_texts *)malloc(sizeof(t_texts))) == NULL)
		exit(-1);
	env->txt->line = NULL;
	env->txt->next = NULL;
}

t_room	*ft_inanthill(t_room *forcpy, t_room *start)
{
	int		i;
	t_room	*copy;

	i = 0;
	copy = NULL;
	copy = ft_initroom(copy);
	while (start->next[i] != NULL)
		i++;
	ft_memcpy(copy, forcpy, sizeof(t_room));
	copy->prev[0] = start;
	copy->next[0] = NULL;
	start->next[i] = copy;
	return (start);
}
