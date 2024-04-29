/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtsuji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:14:37 by mtsuji            #+#    #+#             */
/*   Updated: 2024/04/27 17:14:39 by mtsuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize_movement(int num_ants, int **rooms, bool **arrived)
{
	*rooms = create_empty_rooms(num_ants);
	*arrived = ft_calloc(num_ants, sizeof(bool));
	if (*rooms == NULL || *arrived == NULL)
	{
		printf("Failed to allocate memory");
		exit(1);
	}
}

void	move_single_ant(t_path **paths,
		t_ant_movement *move_params, bool *moved)
{
	t_path				*path;
	t_ant_move_params	params;

	path = find_path_for_ant(paths, move_params->ant->path_index);
	if (path != NULL)
	{
		params.ant = move_params->ant;
		params.path = path;
		params.rooms = move_params->rooms;
		params.arrived = move_params->arrived;
		params.end_room_id = move_params->end_room_id;
		move_ant(&params, moved);
	}
}

void	process_ants_movement(t_movement_context *context)
{
	int				i;
	t_ant_movement	move_params;

	move_params.rooms = context->rooms;
	move_params.arrived = context->arrived;
	move_params.end_room_id = context->end_room_id;
	i = 0;
	while (i < context->num_ants)
	{
		if (!context->arrived[i])
		{
			move_params.ant = &context->ants[i];
			move_single_ant(context->paths, &move_params, context->moved);
		}
		i++;
	}
}

void	cleanup_movement_resources(int *rooms, bool *arrived)
{
	free(rooms);
	free(arrived);
}

void	move_ants(t_path **paths, t_ant *ants, int num_ants, int end_room_id)
{
	int					*rooms;
	bool				*arrived;
	bool				moved;
	t_movement_context	context;

	moved = true;
	initialize_movement(num_ants, &rooms, &arrived);
	context.paths = paths;
	context.ants = ants;
	context.rooms = rooms;
	context.arrived = arrived;
	context.moved = &moved;
	context.num_ants = num_ants;
	context.end_room_id = end_room_id;
	while (moved)
	{
		moved = false;
		ft_memset(rooms, 0, num_ants * sizeof(int));
		process_ants_movement(&context);
		if (moved)
			printf("\n");
	}
	cleanup_movement_resources(rooms, arrived);
}
