/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:13:11 by emaune            #+#    #+#             */
/*   Updated: 2018/08/16 12:28:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			malloc_data(t_main *var)
{
	var->data = (t_data*)malloc(sizeof(t_data));
	var->data_tail = var->data;
	var->data->line_number = 1;
	var->data->line = NULL;
	var->data->prev = NULL;
	var->data->next = NULL;
}
