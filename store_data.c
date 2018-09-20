/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:20:02 by emaune            #+#    #+#             */
/*   Updated: 2018/08/16 13:50:03 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_error(t_main *var)
{
	free(var->data);
	ft_putendl("\x1b[31mError: File is Empty\x1b[0m");
	exit(EXIT_FAILURE);
}

static void		add_line(t_data *data, char *line)
{
	data->line = line;
	data->next = (t_data*)malloc(sizeof(t_data));
	data->next->prev = data;
	data->next->line_number = data->line_number + 1;
}

void			store_data(t_main *var)
{
	int			fd_is_empty;
	char		*line;

	fd_is_empty = 1;
	while (get_next_line(0, &line) > 0)
	{
		fd_is_empty = 0;
		add_line(var->data_tail, line);
		var->data_tail = var->data_tail->next;
	}
	if (fd_is_empty)
		print_error(var);
	var->data_tail = var->data_tail->prev;
	free(var->data_tail->next);
	var->data_tail->next = NULL;
	var->data_tail = var->data;
}
