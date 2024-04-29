/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmondskarp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:29:53 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 18:29:55 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize_params(t_find_path_params *params, t_room *rooms)
{
	int		room_count;
	t_room	*tmp;

	room_count = 0;
	tmp = rooms;
	while (tmp)
	{
		tmp = tmp->next;
		room_count++;
	}
	params->room_count = room_count;
	params->visited = create_empty_visited(room_count, params->startRoomId);
}

t_path	*execute_search(t_find_path_params *params, \
	t_link *links, int startRoomId)
{
	while (true)
	{
		if (!find_path(params))
			break ;
		update_visited(params->visited, *(params->paths), \
			params->room_count, params->endRoomId);
		if (!exist_second_step(links, startRoomId, params->visited))
			break ;
	}
	return (*(params->paths));
}

t_path	*bfs_with_ant(t_room *rooms, t_link *links, \
	int startRoomId, int endRoomId)
{
	t_find_path_params	params;
	t_path				*paths;

	paths = NULL;
	params.paths = &paths;
	params.links = links;
	params.startRoomId = startRoomId;
	params.endRoomId = endRoomId;
	params.room_count = 0;
	params.paths = &paths;
	params.visited = NULL;
	initialize_params(&params, rooms);
	if (!params.visited)
		return (NULL);
	paths = execute_search(&params, links, startRoomId);
	free(params.visited);
	return (paths);
}
