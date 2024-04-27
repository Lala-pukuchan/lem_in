/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:20:55 by mtsuji            #+#    #+#             */
/*   Updated: 2024/04/27 13:20:56 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	find_best_path(t_distribution *dist)
{
	int		best_path_index;
	int		min_length;
	int		path_index;
	int		current_length;
	t_path	*current_path;

	best_path_index = 0;
	min_length = INT_MAX;
	path_index = 0;
	current_path = *dist->paths;
	while (current_path != NULL)
	{
		current_length = current_path->room_count \
			+ dist->ants_in_path[path_index];
		if (current_length < min_length)
		{
			min_length = current_length;
			best_path_index = path_index;
		}
		current_path = current_path->next;
		path_index++;
	}
	return (best_path_index);
}

void	distribute_ants(t_path **paths, int num_paths, int num_ants,
						t_ant *ants)
{
	int				*ants_in_path;
	int				i;
	int				best_path_index;
	t_distribution	dist;

	ants_in_path = calloc(num_paths, sizeof(int));
	if (!ants_in_path)
	{
		perror("Failed to allocate memory for ants_in_path");
		return ;
	}
	dist.paths = paths;
	dist.ants_in_path = ants_in_path;
	dist.num_paths = num_paths;
	i = -1;
	while (++i < num_ants)
	{
		best_path_index = find_best_path(&dist);
		ants_in_path[best_path_index]++;
		ants[i].ant_id = i + 1;
		ants[i].path_index = best_path_index;
	}
	free(ants_in_path);
}

int	*create_empty_rooms(int room_count)
{
	int	*rooms;

	rooms = malloc(room_count * sizeof(int));
	if (!rooms)
		return (NULL);
	memset(rooms, 0, room_count * sizeof(int));
	return (rooms);
}

void	move_ant(t_ant_move_params *params, bool *moved)
{
	int	current_room_id;
	int	next_room_index;
	int	next_room_id;

	current_room_id = params->path->room_ids[params->ant->current_position];
	next_room_index = params->ant->current_position + 1;
	if (next_room_index < params->path->room_count)
	{
		next_room_id = params->path->room_ids[next_room_index];
		if (params->rooms[next_room_id] == 0 || \
			next_room_id == params->end_room_id)
		{
			printf("L%d-%s ", params->ant->ant_id, roomNames[next_room_id]);
			params->rooms[current_room_id] = 0;
			params->ant->current_position = next_room_index;
			params->rooms[next_room_id] = 1;
			*moved = true;
			if (next_room_id == params->end_room_id)
				params->arrived[params->ant->ant_id - 1] = true;
		}
	}
}

t_path	*find_path_for_ant(t_path **paths, int path_index)
{
	t_path	*path;
	int		current_index;

	path = *paths;
	current_index = -1;
	while (path != NULL && ++current_index < path_index)
		path = path->next;
	return (path);
}
