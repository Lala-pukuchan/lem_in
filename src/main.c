/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:24:34 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/19 15:44:18 by rukobaya         ###   ########.fr       */
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
	bfs_with_ant(rooms, links, startRoomId, endRoomId);
	output_details(number_of_ants, rooms, links);
	free_rooms(&rooms);
	free_links(&links);
	system("leaks lem-in");
	return (0);
}
