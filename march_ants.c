/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:24:55 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 11:35:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		reset_flags(t_path *p)
{
	while (p)
	{
		p->room->was_visited = 0;
		p = p->next;
	}
}

void			move_ant_to_end(t_path *p, t_main *var, int *ant)
{
	if (p->next->room->total_ants > 0)
	{
		if (p->next->room == var->start && var->start->total_ants > 0)
		{
			p->next->room->ant_name = ft_itoa(*ant);
			p->next->room->total_ants--;
			p->room->total_ants++;
			ft_putchar('L');
			ft_putstr(p->next->room->ant_name);
			ft_putchar('-');
			ft_putstr(p->room->room_name);
			ft_strdel(&p->next->room->ant_name);
		}
		else if (!p->next->room->was_visited)
		{
			ft_putchar('L');
			ft_putstr(p->next->room->ant_name);
			ft_putchar('-');
			ft_putstr(p->room->room_name);
			ft_strdel(&p->next->room->ant_name);
			p->room->total_ants++;
			p->next->room->total_ants--;
		}
		ft_putchar(' ');
	}
}

void			move_ant_to_next_room(t_path *p, t_main *var, int *ant)
{
	if (p->next->room->total_ants > 0 && !p->room->total_ants)
	{
		if (p->next->room == var->start && var->start->total_ants > 0)
		{
			p->next->room->ant_name = ft_itoa(*ant);
			p->room->ant_name = p->next->room->ant_name;
			p->next->room->total_ants--;
			p->room->total_ants++;
			ft_putchar('L');
			ft_putstr(p->room->ant_name);
			ft_putchar('-');
			ft_putstr(p->room->room_name);
		}
		else if (!p->next->room->was_visited)
		{
			p->room->ant_name = p->next->room->ant_name;
			p->room->total_ants++;
			p->next->room->total_ants--;
			ft_putchar('L');
			ft_putstr(p->room->ant_name);
			ft_putchar('-');
			ft_putstr(p->room->room_name);
		}
		ft_putchar(' ');
	}
}

void			move_ants(t_path *p, t_main *var, int *ant)
{
	if (p->room == var->end)
	{
		if (p->next)
		{
			move_ant_to_end(p, var, ant);
			if (p->next->room == var->start
					&& var->start->total_ants > 0)
				*ant += 1;
			p->room->was_visited = 1;
		}
	}
	else
	{
		if (p->next)
		{
			move_ant_to_next_room(p, var, ant);
			if (p->next->room == var->start
					&& var->start->total_ants > 0 && !p->room->was_visited)
				*ant += 1;
			p->room->was_visited = 1;
		}
	}
}

void			march_ants(t_main *var)
{
	t_path		*p;
	int			ant;
	int			x;

	ant = 1;
	while (1)
	{
		if (var->end->total_ants == var->total_ants)
			break ;
		p = var->path;
		reset_flags(p);
		while (p)
		{
			if (p->room == var->start)
			{
				p = p->next;
				continue ;
			}
			move_ants(p, var, &ant);
			p = p->next;
		}
		ft_putendl("");
	}
}
