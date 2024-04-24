#include "../includes/lem_in.h"

void	distribute_ants(t_path **paths, int num_paths, int num_ants,
		t_ant *ants)
{
	int	best_path_index;
	int	min_length;
	int	path_index;
	int	current_length;

	int *ants_in_path = calloc(num_paths, sizeof(int));
		// Track ants in each path
	if (!ants_in_path)
	{
		perror("Failed to allocate memory for ants_in_path");
		return ;
	}
	for (int i = 0; i < num_ants; i++)
	{
		best_path_index = 0;
		min_length = INT_MAX;
		path_index = 0;
		// Traverse the linked list to find the best path
		for (t_path *current_path = *paths; current_path != NULL; current_path = current_path->next,
			path_index++)
		{
			current_length = current_path->room_count
				+ ants_in_path[path_index];
			if (current_length < min_length)
			{
				min_length = current_length;
				best_path_index = path_index;
			}
		}
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

void	move_ants(t_path **paths, t_ant *ants, int num_ants, int end_room_id)
{
	int *rooms = create_empty_rooms(num_ants);     
		// Assuming this creates an array of size num_ants initialized to 0
	bool *arrived = calloc(num_ants, sizeof(bool));
		// Track arrival status of each ant
	bool moved = true;
	while (moved)
	{
		moved = false;
		memset(rooms, 0, num_ants * sizeof(int));
			// Reset room occupancy at the beginning of each turn

		for (int i = 0; i < num_ants; i++)
		{
			if (arrived[i])
				continue ; // Skip ants that have already arrived at the end

			t_ant *ant = &ants[i];
			int path_index = 0;
			t_path *path = *paths;

			// Find the correct path for the current ant
			while (path != NULL && path_index < ant->path_index)
			{
				path = path->next;
				path_index++;
			}

			if (path != NULL)
			{ // Ensure the path is found
				int current_room_id = path->room_ids[ant->current_position];
				int next_room_index = ant->current_position + 1;
				if (next_room_index < path->room_count)
				{
					int next_room_id = path->room_ids[next_room_index];
					if (rooms[next_room_id] == 0 || next_room_id == end_room_id)
					{
						// Check if the next room is not occupied or is the end room
						printf("L%d-%d ", ant->ant_id, next_room_id);
						// printf("Ant %d moves from room %d to room %d.\n",
                        // ant->ant_id, current_room_id, next_room_id);
						rooms[current_room_id] = 0;
							// Mark the current room as unoccupied
						ant->current_position = next_room_index;
						rooms[next_room_id] = 1;
							// Mark the new room as occupied
						moved = true;

						if (next_room_id == end_room_id)
						{
							arrived[i] = true;
								// Mark this ant as having arrived
							// printf("Ant %d has arrived at the end room
								//%d.\n", ant->ant_id, end_room_id);
						}
					}
					else
					{
						// printf("Room %d is occupied, Ant
							//%d cannot move there.\n", next_room_id,
							//ant->ant_id);
					}
				}
			}
		}
		if (moved)
		{
			// printf("End of turn.\n\n");
			printf("\n");
		}
	}
	free(rooms);
	free(arrived);
}