/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:19:32 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 16:19:33 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_count = 0;

void	initialize_room_names(int num_rooms)
{
	int	i;

	g_room_names = malloc(num_rooms * sizeof(char *));
	if (g_room_names == NULL)
	{
		printf("Memory allocation failed for room names.\n");
		exit(1);
	}
	i = 0;
	while (i < num_rooms)
	{
		g_room_names[i] = NULL;
		i++;
	}
}

t_room	*add_room(t_room **rooms, char *name, int x, int y, int is_start,
		int is_end)
{
	t_room	*new_room;

	new_room = malloc(sizeof(t_room));
	if (new_room == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	new_room->id = room_count;
	room_count++;
	new_room->name = strdup(name);
	g_room_names[new_room->id] = strdup(name);
	new_room->x = x;
	new_room->y = y;
	new_room->is_start = is_start;
	new_room->is_end = is_end;
	new_room->next = *rooms;
	*rooms = new_room;
	return (new_room);
}

void	free_rooms(t_room **rooms)
{
	t_room	*current;
	t_room	*next;

	current = *rooms;
	while (current != NULL)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	*rooms = NULL;
}

void	free_room_names(void)
{
	int	i;

	i = 0;
	while (i < MAX_ROOM_SIZE)
	{
		free(g_room_names[i]);
		i++;
	}
	free(g_room_names);
}
