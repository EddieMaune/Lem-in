/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:50:50 by emaune            #+#    #+#             */
/*   Updated: 2018/08/30 13:39:33 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		print_map(t_data *data)
{
	ft_putstr("\x1b[32m");
	while (data)
	{
		if (ft_strequ(data->line, "##start") || ft_strequ(data->line, "##end"))
			ft_putstr("\x1b[34;1m");
		if (is_room(data->line))
			ft_putstr("\x1b[35;1m");
		if (is_link(data->line))
			ft_putstr("\x1b[33m");
		if (is_comment(data->line))
			ft_putstr("\x1b[36;1m");
		ft_putendl(data->line);
		ft_putstr("\x1b[0m");
		data = data->next;
	}
	ft_putendl("");
}

static void		free_everything(t_main *var)
{
	free_data(var->data);
	free_rooms(var->rooms);
	free_links(var->links);
	free_route(var->route);
	free_path(var->path);
}

void			init_total_ants(t_main *var)
{
	t_data		*data;

	data = var->data;
	while (is_comment(data->line))
		data = data->next;
	var->total_ants = ft_atoi(data->line);
}

int				main(void)
{
	t_main		var;

	var.rooms = NULL;
	var.links = NULL;
	read_data(&var);
	error_check_multiple_start_end(&var);
	error_check_data(var.data);
	init_total_ants(&var);
	create_rooms(&var);
	error_check_rooms(&var);
	create_links(&var);
	error_check_links(&var);
	link_rooms(&var);
	count_routes(var.rooms, &var);
	var.path = NULL;
	set_path(var.route, &var);
	var.start = get_start_room(var.rooms);
	var.end = get_end_room(var.rooms);
	print_map(var.data);
	ft_putstr("\x1b[32;1m");
	march_ants(&var);
	ft_putstr("\x1b[0m");
	free_everything(&var);
	return (0);
}
