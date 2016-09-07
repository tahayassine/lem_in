/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:51:16 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/28 11:20:19 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_addinput(t_queue *queue, t_room *room)
{
	t_queue *tmp;
	t_queue *new;

	new = (t_queue *)malloc(sizeof(t_queue));
	tmp = queue;
	while (queue->next != NULL)
		queue = queue->next;
	new->output = room;
	new->ok = 0;
	new->next = NULL;
	queue->next = new;
	queue = tmp;
}

int		ft_read_line(char *line, t_param *env, t_anthill *anthill)
{
	int	retcom;
	int	retroom;

	retroom = 10;
	retcom = ft_checkcom(line, env);
	if (retcom == 1)
		return (0);
	if ((env->antsnbr > 0 && retcom == 0 && env->tub == NULL) &&
			(env->start != 1 && env->end != 1))
		retroom = ft_checkroom(line, env);
	else if (env->antsnbr == 0 && ft_checkants(line, env) == 1)
		return (0);
	else if ((env->start == 1) && (env->end == 1))
		ft_errorandexit(10);
	else if ((env->start == 1) || (env->end == 1))
	{
		ft_anthillstartend(line, env, anthill);
		return (0);
	}
	ft_read_line_suite(line, env, anthill, retroom);
	return (0);
}

int		ft_read_line_suite(char *line, t_param *env, t_anthill *anthill,
		int retroom)
{
	int	retcom;

	retcom = ft_checkcom(line, env);
	if ((retcom == 0) && (env->tub != NULL))
	{
		if ((ft_checktube(line, env, anthill) == 0) || (retroom == 1))
			ft_errorandexit(10);
		return (0);
	}
	if ((retcom == 0) && (env->tub == NULL))
	{
		if ((retroom == 0) && (env->start != 2 || env->end != 2))
			ft_errorandexit(10);
		else if (retroom == 2)
			ft_checktube(line, env, anthill);
		return (0);
	}
	return (0);
}

void	ft_buffline(char *line, t_texts *text)
{
	t_texts		*new;
	t_texts		*txt;

	txt = text;
	if (text->line == NULL)
		text->line = ft_strdup(line);
	else
	{
		if ((new = (t_texts *)malloc(sizeof(t_texts))) == NULL)
			exit(-1);
		new->line = ft_strdup(line);
		new->next = NULL;
		while (txt->next != NULL)
		{
			txt = txt->next;
		}
		txt->next = new;
	}
}

int		ft_parse(t_param *env, t_anthill *anthill)
{
	char	*line;
	int		flag;

	flag = 0;
	while ((get_next_line(0, &line)) == 1)
	{
		flag++;
		ft_read_line(line, env, anthill);
		ft_buffline(line, env->txt);
		free(line);
	}
	if (flag == 0)
		ft_errorandexit(10);
	return (1);
}
