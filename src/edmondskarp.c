#include "../includes/lem_in.h"
#include <stdbool.h> // For using bool type
#include <stdlib.h>  // Include for malloc and NULL

int	*create_empty_visited(int room_count, int startRoomId)
{
	int	*visited;

	visited = malloc(room_count * sizeof(int));
	if (!visited)
		return (NULL);
	memset(visited, 0, room_count * sizeof(int));
	visited[startRoomId] = 1;
	printf("startRoomId: %d\n", startRoomId);
	return (visited);
}

void	update_visited(int *visited, t_path *paths, int room_count,
		int endRoomId)
{
	t_path	*tmp;

	for (int i = 0; i < room_count; i++)
	{
		visited[i] = 0;
		printf("visited room Id in update: %d\n", i);
	}
	tmp = paths;
	while (tmp)
	{
		for (int i = 0; i < tmp->room_count; i++)
		{
			visited[tmp->room_ids[i]] = 1;
			printf("visited room Id in update: %d\n", tmp->room_ids[i]);
		}
		tmp = tmp->next;
	}
	visited[endRoomId] = 0;
}

int	find_path(t_link *links, int startRoomId, int endRoomId, int visited[],
		t_path **paths, int room_count)
{
	int	*queue;
	int	front;
	int	rear;
	int	*predecessors;
	int	uId;
	int	path_length;
	int	*path;
	int	at;

	front = 0, rear = 0;
	queue = malloc(room_count * sizeof(int));
	front = 0, rear = 0;
	queue[rear++] = startRoomId;
	predecessors = malloc(room_count * sizeof(int));
	for (int i = 0; i < room_count; i++)
	{
		predecessors[i] = -1;
	}
	while (front < rear)
	{
		uId = queue[front++];
		if (uId == endRoomId)
		{
			path_length = 0;
			for (int at = endRoomId; at != -1; at = predecessors[at])
			{
				path_length++;
			}
			path = malloc(path_length * sizeof(int));
			at = endRoomId;
			for (int i = path_length - 1; i >= 0; i--)
			{
				path[i] = at;
				at = predecessors[at];
			}
			*paths = add_path(paths, path, path_length);
			free(path);
			free(queue);
			free(predecessors);
			return (true);
		}
		for (t_link *link = links; link; link = link->next)
		{
			if (link->startId == uId && !visited[link->endId])
			{
				queue[rear++] = link->endId;
				visited[link->endId] = 1;
				predecessors[link->endId] = uId;
			}
		}
	}
	free(queue);
	free(predecessors);
	return (false);
}

bool	exist_second_step(t_link *links, int startRoomId, int *visited)
{
	t_link	*currentLink;

	currentLink = links;
	while (currentLink != NULL)
	{
		if (currentLink->startId == startRoomId && !visited[currentLink->endId])
		{
			printf("found an unvisited room connected to the start room: %d\n",
				currentLink->endId);
			return (true);
		}
		currentLink = currentLink->next;
	}
	return (false);
}

t_path	*bfs_with_ant(t_room *rooms, t_link *links, int startRoomId,
		int endRoomId)
{
	t_path	*paths;
	int		room_count;
	t_room	*tmp;
	int		*visited;
	int		*tmp2;
	int		res;

	paths = NULL;
	room_count = 0;
	tmp = rooms;
	while (tmp)
	{
		printf("room: %s, id: %d\n", tmp->name, tmp->id);
		tmp = tmp->next;
		room_count++;
	}
	visited = create_empty_visited(room_count, startRoomId);
	res = 0;
	while (1)
	{
		res = find_path(links, startRoomId, endRoomId, visited, &paths,
				room_count);
		if (res == false)
		{
			printf("No path found\n");
			break ;
		}
		update_visited(visited, paths, room_count, endRoomId);
		tmp2 = visited;
		for (int i = 0; i < room_count; i++)
		{
			printf("visited: %d\n", tmp2[i]);
		}
		if (!exist_second_step(links, startRoomId, visited))
		{
			printf("No more paths to explore\n");
			break ;
		}
	}
	free(visited);
	return (paths);
}
