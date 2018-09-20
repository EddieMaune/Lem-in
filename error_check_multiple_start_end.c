/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_multiple_start_end.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 13:31:56 by emaune            #+#    #+#             */
/*   Updated: 2018/08/27 11:30:49 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		check_line(t_main *var, char *line, int *start, int *end)
{
	if (ft_strequ(line, "##start") && !*start)
		*start = 1;
	else if (ft_strequ(line, "##start"))
	{
		ft_putendl("\x1b[31mError: Multiple start room");
		free(var->data);
		exit(1);
	}
	if (ft_strequ(line, "##end") && !*end)
		*end = 1;
	else if (ft_strequ(line, "##end"))
	{
		ft_putendl("\x1b[31mError: Multiple end room");
		free(var->data);
		exit(1);
	}
}

void			error_check_multiple_start_end(t_main *var)
{
	int			start;
	int			end;
	t_data		*data;

	start = 0;
	end = 0;
	data = var->data;
	while (data)
	{
		check_line(var, data->line, &start, &end);
		data = data->next;
	}
}
