/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_edmondskarp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:04:19 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 20:04:21 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	*create_empty_visited(int room_count, int startRoomId)
{
	int	*visited;

	visited = malloc(room_count * sizeof(int));
	if (!visited)
		return (NULL);
	ft_memset(visited, 0, room_count * sizeof(int));
	visited[startRoomId] = 1;
	return (visited);
}

void	update_visited(int *visited, t_path *paths, \
	int room_count, int endRoomId)
{
	t_path	*tmp;
	int		index;
	int		i;

	index = 0;
	tmp = paths;
	while (index < room_count)
		visited[index++] = 0;
	while (tmp)
	{
		i = 0;
		while (i < tmp->room_count)
		{
			visited[tmp->room_ids[i++]] = 1;
		}
		tmp = tmp->next;
	}
	visited[endRoomId] = 0;
}

int	initialize_find_path_params(t_find_path_params *params)
{
	params->queue = malloc(params->room_count * sizeof(int));
	params->predecessors = malloc(params->room_count * sizeof(int));
	params->front = 0;
	params->rear = 0;
	if (!params->queue || !params->predecessors)
	{
		free(params->queue);
		free(params->predecessors);
		return (0);
	}
	memset(params->predecessors, -1, params->room_count * sizeof(int));
	return (1);
}

int	calculate_path_length(int *predecessors, int endRoomId)
{
	int	length;
	int	at;

	length = 0;
	at = endRoomId;
	while (at != -1)
	{
		length++;
		at = predecessors[at];
	}
	return (length);
}

int	*construct_path(int *predecessors, int path_length, int endRoomId)
{
	int	*path;
	int	i;
	int	at;

	path = malloc(path_length * sizeof(int));
	i = path_length - 1;
	at = endRoomId;
	if (path)
	{
		while (i >= 0)
		{
			path[i--] = at;
			at = predecessors[at];
		}
	}
	return (path);
}
