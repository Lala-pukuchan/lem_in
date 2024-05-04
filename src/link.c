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

char	*get_room_name_by_id(t_room *rooms, int room_id)
{
	t_room	*current;

	current = rooms;
	while (current != NULL)
	{
		if (current->id == room_id)
		{
			return (current->name);
		}
		current = current->next;
	}
	return (NULL);
}

t_link	*add_link_both_order(t_link **links, t_link_info *info, \
	bool opposite)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (new_link == NULL)
	{
		ft_printf("Memory allocation failed.\n");
		exit(1);
	}
	new_link->start_id = get_room_id(info->rooms, info->start);
	new_link->end_id = get_room_id(info->rooms, info->end);
	new_link->start_name = ft_strdup(get_room_name_by_id(info->rooms, \
		new_link->start_id));
	new_link->end_name = ft_strdup(get_room_name_by_id(info->rooms, \
		new_link->end_id));
	new_link->opposite = opposite;
	new_link->next = *links;
	*links = new_link;
	return (new_link);
}

void	add_link(t_link **links, char *start, char *end, t_room *rooms)
{
	t_link_info	start_to_end_info;
	t_link_info	end_to_start_info;

	start_to_end_info.start = start;
	start_to_end_info.end = end;
	start_to_end_info.rooms = rooms;
	end_to_start_info.start = end;
	end_to_start_info.end = start;
	end_to_start_info.rooms = rooms;
	add_link_both_order(links, &start_to_end_info, false);
	add_link_both_order(links, &end_to_start_info, true);
}

void	free_links(t_link **links)
{
	t_link	*current;
	t_link	*next;

	current = *links;
	while (current != NULL)
	{
		next = current->next;
		free(current->start_name);
		free(current->end_name);
		free(current);
		current = next;
	}
	*links = NULL;
}
