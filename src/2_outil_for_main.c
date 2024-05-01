/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:24:34 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/24 17:34:57 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_resources(t_room *rooms, t_link *links, \
	t_path *paths)
{
	if (rooms != NULL)
		free_rooms(&rooms);
	if (links != NULL)
		free_links(&links);
	if (paths != NULL)
		free_paths(&paths);
}

int	validate_ants_number(int number_of_ants, t_room *rooms, \
	t_link *links)
{
	if (check_ants(number_of_ants, rooms, links) != 0)
		return (ft_putstr_fd("Invalid number of ants.\n", \
			STDERR_FILENO), 1);
	return (0);
}

int	validate_flags(t_room *rooms, t_link *links, \
	int start_flag, int end_flag)
{
	if (check_flags(rooms, links, start_flag, end_flag) != 0)
	{
		return (ft_putstr_fd("Invalid flag configuration.\n", \
			STDERR_FILENO), 1);
	}
	return (0);
}

void	initialize_ants(t_ant *ants, int number_of_ants)
{
	int	i;

	i = 0;
	while (i < number_of_ants)
	{
		ants[i].ant_id = i + 1;
		ants[i].path_index = -1;
		ants[i].current_position = 0;
		i++;
	}
}

int	count_paths(t_path *paths)
{
	int	count;

	count = 0;
	while (paths)
	{
		paths = paths->next;
		count++;
	}
	return (count);
}
