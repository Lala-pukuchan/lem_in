#include "../includes/lem_in.h"

int		roomCount = 0;

void	initializeRoomNames(int numRooms)
{
	roomNames = malloc(numRooms * sizeof(char *));
	if (roomNames == NULL)
	{
		printf("Memory allocation failed for room names.\n");
		exit(1);
	}
	for (int i = 0; i < numRooms; i++)
	{
		roomNames[i] = NULL;
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
	new_room->id = roomCount;
	roomCount++;
	new_room->name = strdup(name);
	roomNames[new_room->id] = strdup(name);
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

void	freeRoomNames(void)
{
	for (int i = 0; i < MAX_ROOM_SIZE; i++)
	{
		free(roomNames[i]);
	}
	free(roomNames);
}