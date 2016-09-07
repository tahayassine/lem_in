/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:50:28 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/28 11:19:36 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*ft_anthillson(t_param *env, char *t_1, char *t_2, t_room *start)
{
	t_room	*tmp;

	tmp = env->tab;
	while (env->tab != NULL)
	{
		if (((ft_strcmp(t_1, start->name) == 0) &&
			(ft_strcmp(t_2, env->tab->name) == 0)) ||
			((ft_strcmp(t_1, env->tab->name) == 0) &&
			(ft_strcmp(t_2, start->name) == 0)))
		{
			start = ft_inanthill(env->tab, start);
			env->tab = tmp;
			return (start);
		}
		env->tab = env->tab->next[0];
	}
	env->tab = tmp;
	return (start);
}

t_room	*ft_connectrecursive(t_param *env, t_room *start, t_anthill *anthill,
		t_queue *queue)
{
	t_tube	*tmp;

	tmp = env->tub;
	while (env->tub)
	{
		if (env->tub->use == 0 && ((ft_strcmp(env->tub->t_1, start->name) == 0)
					|| (ft_strcmp(env->tub->t_2, start->name)) == 0))
		{
			env->tub->use++;
			if ((ft_strcmp(env->tub->t_1, anthill->end->name) == 0) ||
					(ft_strcmp(env->tub->t_2, anthill->end->name) == 0))
			{
				ft_endrecursive(env, anthill, start, tmp);
				return (start);
			}
			else
				start = ft_anthillson(env, env->tub->t_1, env->tub->t_2, start);
		}
		env->tub = env->tub->next;
	}
	env->tub = tmp;
	start = ft_anthillstartnext(start, queue);
	if (ft_checkusepipe(env, start, queue) == 1)
		ft_connectrecursive(env, start, anthill, queue);
	return (start);
}

void	ft_endrecursive(t_param *env, t_anthill *anthill, t_room *start,
		t_tube *tmp)
{
	ft_inanthillend(anthill, start);
	env->tub = tmp;
}

void	ft_inanthillend(t_anthill *anthill, t_room *start)
{
	t_room *tmp;
	t_room *tmp2;

	tmp = anthill->end;
	tmp2 = malloc(sizeof(t_room));
	anthill->end->prev[0] = start;
	while (anthill->end->prev[0] != NULL)
	{
		tmp2 = anthill->end;
		anthill->end = anthill->end->prev[0];
		anthill->end->next[0] = tmp2;
	}
	anthill->end = tmp;
}

t_room	*ft_anthillstartnext(t_room *start, t_queue *queue)
{
	int		i;
	t_queue *tmp;

	i = 0;
	while (queue->ok == 1 && queue->next != NULL)
		queue = queue->next;
	if (queue->ok == 1 && queue->next == NULL)
		ft_initqueue(queue);
	tmp = queue;
	if (start->next[i] != NULL)
	{
		while (start->next[i] != NULL)
		{
			if (queue->output == NULL)
			{
				ft_firstqueue(queue, start->next[i]);
				tmp = queue;
			}
			else
				ft_addinput(queue, start->next[i]);
			i++;
		}
	}
	queue->ok = 1;
	return (queue->output);
}
