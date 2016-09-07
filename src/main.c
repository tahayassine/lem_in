/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:29:27 by tyassine          #+#    #+#             */
/*   Updated: 2016/09/05 16:40:26 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_counttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	i--;
	return (i);
}

int		ft_checkroomname(char **room_name)
{
	if (ft_counttab(room_name) != 2)
		ft_errorandexit(1);
	if ((ft_isnum(room_name[1]) != 0) || (ft_isnum(room_name[2]) != 0))
		ft_errorandexit(1);
	if (room_name[0][0] == 'L')
		ft_errorandexit(1);
	return (0);
}

int		ft_checkpipename(char **pipe, t_param *env, t_anthill *anthill)
{
	t_room		*tmp;
	int			ok;

	tmp = env->tab;
	ok = 0;
	if ((ft_counttab(pipe) != 1) || (ft_strcmp(pipe[0], pipe[1]) == 0))
		ft_errorandexit(2);
	while (env->tab != NULL)
	{
		if (ft_strcmp(env->tab->name, pipe[0]) == 0)
			ok++;
		if (ft_strcmp(env->tab->name, pipe[1]) == 0)
			ok++;
		env->tab = env->tab->next[0];
	}
	env->tab = tmp;
	if ((ft_strcmp(anthill->start->name, pipe[0]) == 0) ||
	(ft_strcmp(anthill->start->name, pipe[1]) == 0))
		ok++;
	if ((ft_strcmp(anthill->end->name, pipe[0]) == 0) ||
	(ft_strcmp(anthill->end->name, pipe[1]) == 0))
		ok++;
	if (ok != 2)
		ft_errorandexit(2);
	return (0);
}

void	ft_firstqueue(t_queue *queue, t_room *room)
{
	queue->output = room;
	queue->next = NULL;
	queue->ok = 0;
}

int		main(void)
{
	t_param		*env;
	t_anthill	*anthill;
	t_queue		*queue;

	if ((env = (t_param *)malloc(sizeof(t_param))) == NULL
		|| (anthill = (t_anthill *)malloc(sizeof(t_anthill))) == NULL
		|| (queue = (t_queue *)malloc(sizeof(t_queue))) == NULL)
		return (-1);
	ft_initialenv(env);
	ft_initialanthill(anthill);
	ft_initqueue(queue);
	if (ft_parse(env, anthill) == 1)
	{
		ft_lineprint(env->txt);
		ft_connect(env, anthill, queue);
	}
	ft_freeanthill(anthill);
	ft_freequeue(queue);
	ft_freeenv(env);
	return (0);
}
