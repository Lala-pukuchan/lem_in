/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:24:34 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/24 13:57:12 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	main(void)
{
	char	input[MAX_INPUT_SIZE];
	int		number_of_ants;
	t_room	*rooms;
	t_link	*links;
	int		state;
	int		startFlag;
	int		endFlag;
	int		startRoomId;
	int		endRoomId;
	char	*name;
	int		x;
	int		y;
	char	*start;
	char	*end;
	int		res;
	t_path	*paths;
	t_path	*tmp1;
	int		pathCount;
	t_ant	*ants;

	number_of_ants = -1;
	rooms = NULL;
	links = NULL;
	state = 0;
	startFlag = 0;
	endFlag = 0;
	startRoomId = -1;
	endRoomId = -1;
	while (fgets(input, MAX_INPUT_SIZE, stdin) != NULL)
	{
		input[strcspn(input, "\n")] = 0;
		if (input[0] == '#')
		{
			if (ft_strncmp(input, "##start", 6) == 0)
			{
				startFlag = 1;
				state = 1;
				continue ;
			}
			else if (ft_strncmp(input, "##end", 4) == 0)
			{
				endFlag = 1;
				continue ;
			}
			continue ;
		}
		if (state == 0)
		{
			number_of_ants = ft_atoi(input);
			if (number_of_ants <= 0)
			{
				printf("Invalid number of ants.\n");
				return (1);
			}
			state = 1;
		}
		else if (state == 1)
		{
			if (strchr(input, '-') != NULL)
			{
				state = 2;
			}
			else
			{
				name = strtok(input, " ");
				x = ft_atoi(strtok(NULL, " "));
				y = ft_atoi(strtok(NULL, " "));
				if (startFlag == 1)
				{
					rooms = add_room(&rooms, name, x, y, 1, 0);
					startRoomId = rooms->id;
					startFlag++;
				}
				else if (endFlag == 1)
				{
					rooms = add_room(&rooms, name, x, y, 0, 1);
					endRoomId = rooms->id;
					endFlag++;
				}
				else
				{
					rooms = add_room(&rooms, name, x, y, 0, 0);
				}
				continue ;
			}
		}
		if (state == 2)
		{
			start = strtok(input, "-");
			end = strtok(NULL, "-");
			add_link(&links, start, end, rooms);
		}
	}
	if (ferror(stdin))
	{
		printf("Error reading input.\n");
		return (1);
	}
	res = check(number_of_ants, rooms, links, startFlag, endFlag);
	if (res == 1)
	{
		free_rooms(&rooms);
		free_links(&links);
		printf("Invalid ant farm.\n");
		return (1);
	}
	paths = bfs_with_ant(rooms, links, startRoomId, endRoomId);
	reverse_paths(&paths);
	tmp1 = paths;
	pathCount = 0;
	while (tmp1)
	{
		printf("Path: ");
		for (int i = 0; i < tmp1->room_count; i++)
		{
			printf("%d ->", tmp1->room_ids[i]);
		}
		printf("\n");
		tmp1 = tmp1->next;
		pathCount++;
	}
	output_details(number_of_ants, rooms, links);
	// Allocate memory for the ants
	ants = malloc(number_of_ants * sizeof(t_ant));
	if (ants == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for ants.\n");
		return (1); // Exit if memory allocation fails
	}
	// Initialize current position of each ant
	for (int i = 0; i < number_of_ants; i++)
	{
		ants[i].ant_id = i + 1;
		ants[i].path_index = -1;      // Initialize to
			//-1 indicating no path assigned yet
		ants[i].current_position = 0; // Start at the beginning of the path
	}
	// Distribute ants across paths
	printf("pathCount: %d\n", pathCount);
	distribute_ants(&paths, pathCount, number_of_ants, ants);
	move_ants(&paths, ants, number_of_ants, endRoomId);
	// Here you would add logic to move ants along the paths and possibly print their movements
	// Free allocated resources
	free(ants); // Free the memory allocated for ants
	free_rooms(&rooms);
	free_links(&links);
	free_paths(&paths);
	system("leaks lem-in");
	return (0);
}
