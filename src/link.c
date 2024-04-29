/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:02:55 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 16:02:56 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	get_room_id(t_room *rooms, char *name)
{
	int		id;
	t_room	*current;

	id = 0;
	current = rooms;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			id = current->id;
		}
		current = current->next;
	}
	return (id);
}

t_link	*add_link_both_order(t_link **links, char *start, char *end,
		t_room *rooms, bool opposite)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (new_link == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	new_link->startId = get_room_id(rooms, start);
	new_link->endId = get_room_id(rooms, end);
	new_link->opposite = opposite;
	new_link->next = *links;
	*links = new_link;
	return (new_link);
}

void	add_link(t_link **links, char *start, char *end, t_room *rooms)
{
	add_link_both_order(links, start, end, rooms, false);
	add_link_both_order(links, end, start, rooms, true);
}

void	free_links(t_link **links)
{
	t_link	*current;
	t_link	*next;

	current = *links;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*links = NULL;
}
