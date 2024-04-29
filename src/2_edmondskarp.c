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

void	add_path_to_paths(t_path **paths, int *path, int path_length)
{
	t_path	*new_path;

	new_path = malloc(sizeof(t_path));
	if (new_path == NULL)
		return ;
	new_path->room_ids = malloc(path_length * sizeof(int));
	if (new_path->room_ids == NULL)
	{
		free(new_path);
		return ;
	}
	ft_memcpy(new_path->room_ids, path, path_length * sizeof(int));
	new_path->room_count = path_length;
	new_path->next = *paths;
	*paths = new_path;
}

void	update_queue_and_predecessors(t_find_path_params *params, int uId)
{
	t_link	*link;

	link = params->links;
	while (link != NULL)
	{
		if (link->startId == uId && !params->visited[link->endId])
		{
			params->queue[params->rear++] = link->endId;
			params->visited[link->endId] = 1;
			params->predecessors[link->endId] = uId;
		}
		link = link->next;
	}
}

int	process_node(t_find_path_params *params, int uid)
{
	int	path_length;
	int	*path;

	path = NULL;
	if (uid == params->endRoomId)
	{
		path_length = calculate_path_length(params->predecessors, \
			params->endRoomId);
		path = construct_path(params->predecessors, path_length, \
			params->endRoomId);
		add_path_to_paths(params->paths, path, path_length);
		free(path);
		return (1);
	}
	update_queue_and_predecessors(params, uid);
	return (0);
}

int	find_path(t_find_path_params *params)
{
	int	uid;
	int	found;

	found = 0;
	if (!initialize_find_path_params(params))
		return (0);
	params->queue[params->rear++] = params->startRoomId;
	while (params->front != params->rear && !found)
	{
		uid = params->queue[params->front++];
		found = process_node(params, uid);
	}
	free(params->queue);
	free(params->predecessors);
	return (found);
}

bool	exist_second_step(t_link *links, int startRoomId, int *visited)
{
	t_link	*current_link;

	current_link = links;
	while (current_link != NULL)
	{
		if (current_link->startId == startRoomId && \
			!visited[current_link->endId])
			return (true);
		current_link = current_link->next;
	}
	return (false);
}
