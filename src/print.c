/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:34:17 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:48 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_start_room(t_room *rooms_head)
{
	t_room	*current_room;

	current_room = rooms_head;
	while (current_room != NULL)
	{
		if (current_room->is_start)
		{
			ft_printf("##start\n");
			ft_printf("%s %d %d\n", current_room->name, current_room->x,
				current_room->y);
			return ;
		}
		current_room = current_room->next;
	}
}

void	print_end_room(t_room *rooms_head)
{
	t_room	*current_room;

	current_room = rooms_head;
	while (current_room != NULL)
	{
		if (current_room->is_end)
		{
			ft_printf("##end\n");
			ft_printf("%s %d %d\n", current_room->name, current_room->x,
				current_room->y);
			return ;
		}
		current_room = current_room->next;
	}
}

void	output_details(int number_of_ants, t_room *rooms_head,
		t_link *links_head)
{
	t_room	*current_room;
	t_link	*current_link;

	ft_printf("%d\n", number_of_ants);
	print_start_room(rooms_head);
	print_end_room(rooms_head);
	current_room = rooms_head;
	while (current_room != NULL)
	{
		if (!current_room->is_start && !current_room->is_end)
		{
			ft_printf("%s %d %d\n", current_room->name, current_room->x,
				current_room->y);
		}
		current_room = current_room->next;
	}
	current_link = links_head;
	while (current_link != NULL)
	{
		if (!current_link->opposite)
			ft_printf("%s-%s\n", current_link->start_name, \
			current_link->end_name);
		current_link = current_link->next;
	}
	ft_printf("\n");
}
