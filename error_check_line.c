/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:38:17 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 11:40:47 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		is_start_end(char *line)
{
	if (ft_strequ(line, "##start") || ft_strstr(line, "##end"))
	{
		return (1);
	}
	return (0);
}

static void		print_error_message(t_data *data)
{
	ft_putstr("\x1b[31mError: Line - ");
	ft_putnbr(data->line_number);
	ft_putstr("\n\"");
	ft_putstr(data->line);
	ft_putstr("\" is an invalid line.\x1b[0m");
	while (data->prev)
		data = data->prev;
	free_data(data);
	exit(EXIT_FAILURE);
}

void			error_check_line(t_data *data)
{
	if (!is_room(data->line) && !is_comment(data->line)
			&& !is_start_end(data->line) && !is_link(data->line))
		print_error_message(data);
	if (is_start_end(data->line))
	{
		data = data->next;
		if (data)
		{
			while (is_comment(data->line))
				data = data->next;
			if (!is_room(data->line))
			{
				ft_putendl("\x1b[31mError: No start/end room\x1b[0m");
				while (data->prev)
					data = data->prev;
				free_data(data);
				exit(EXIT_FAILURE);
			}
		}
		else
			exit(EXIT_FAILURE);
	}
}
