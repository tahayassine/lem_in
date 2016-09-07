/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debeug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyassine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 23:51:03 by tyassine          #+#    #+#             */
/*   Updated: 2016/07/28 11:17:22 by tyassine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_print(t_param *env, t_anthill *anthill)
{
	ft_printf("\n\033[35mNumber Ants: %d\033[0m\n\n", env->antsnbr);
	ft_printf("Start Name : %s, x : %d, y : %d\n", anthill->start->name,
			anthill->start->x, anthill->start->y);
	ft_printf("End Name : %s, x : %d, y : %d\n\n", anthill->end->name,
			anthill->end->x, anthill->end->y);
	while (env->tab->next[0] != NULL)
	{
		ft_printf("\033[32mOther Room Name : %s, x : %d, y : %d\033[0m\n",
				env->tab->name,
				env->tab->x, env->tab->y);
		env->tab = env->tab->next[0];
	}
	ft_printf("\033[32mOther Room Name : %s, x : %d, y : %d\033[0m\n\n",
			env->tab->name, env->tab->x, env->tab->y);
	while (env->tub->next != NULL)
	{
		ft_printf("Pipe for room %s and  %s, use : %d, number: %d\n",
				env->tub->t_1, env->tub->t_2, env->tub->use, env->tub->nbr);
		env->tub = env->tub->next;
	}
	ft_printf("Pipe for romm %s and  %s, use : %d , number: %d\n\n",
				env->tub->t_1, env->tub->t_2, env->tub->use, env->tub->nbr);
	ft_printf("\033[31m********************************************\033[0m\n");
}

void	ft_print_room(t_room *room)
{
	ft_printf("name:%2.2s->  |X:%2d|Y:%2d|Flag:%2d|Fils:%2d\n", room->name,
			room->x, room->y, room->flag, room->fils);
}

void	ft_print_queue(t_queue *q)
{
	t_queue	*tmpq;

	tmpq = q;
	while (tmpq)
	{
		ft_printf("ok?\n", tmpq->ok);
		ft_print_room(tmpq->output);
		tmpq = tmpq->next;
	}
}

void	ft_print_tub(t_tube *tb)
{
	ft_printf("|%2s|<->|%2s|  N:(%d) use?[%d]\n", tb->t_1, tb->t_2, tb->nbr,
			tb->use);
}

void	print_all(t_param *e, t_anthill *a)
{
	t_room	*room;
	t_tube	*tb;

	room = e->tab;
	tb = e->tub;
	ft_printf("antsnbr:% d\nstar existe?:% d\nend existe?:% d\n", e->antsnbr,
			e->start, e->end);
	ft_printf("\n\nroom: ...\n");
	ft_printf("STAR:%2.2s->X:%2d|Y:%2d|Flag:%2d|Fils:%2d|\n", a->start->name,
			a->start->x, a->start->y, a->start->flag, a->start->fils);
	while (room != NULL)
	{
		ft_print_room(room);
		room = room->next[0];
	}
	ft_printf("END:%2.2s->X:%2d|Y:%2d|Flag:%2d|Fils:%2d|\n", a->end->name,
			a->end->x, a->end->y, a->end->flag, a->end->fils);
	ft_printf("\n\ntube: ...\n");
	while (tb != NULL)
	{
		ft_print_tub(tb);
		tb = tb->next;
	}
	ft_printf("end tub/\n");
}
