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

void	initialize_simulation_config(t_simulation_config *config)
{
	config->state = 0;
	config->start_flag = 0;
	config->end_flag = 0;
	config->start_room_id = -1;
	config->end_room_id = -1;
	config->number_of_ants = -1;
}

void	read_and_parse_input(t_simulation_config *config, t_room **rooms, \
	t_link **links)
{
	char	*input;

	input = get_next_line(STDIN_FILENO);
	while (input != NULL)
	{
		parse_input(input, config, rooms, links);
		free(input);
		input = get_next_line(STDIN_FILENO);
	}
}

void	finalize_simulation(t_room *rooms, t_link *links, t_path *path)
{
	free_resources(rooms, links, path);
	free_room_names();
}

t_path	*setup_simulation(t_simulation_config *config, t_room *rooms, \
	t_link *links, int *path_count)
{
	t_path	*paths;

	paths = bfs_with_ant(rooms, links, config->start_room_id, \
		config->end_room_id);
	reverse_paths(&paths);
	*path_count = count_paths(paths);
	output_details(config->number_of_ants, rooms, links);
	return (paths);
}

int	run_simulation(t_path *paths, int path_count, t_simulation_config *config)
{
	t_ant	*ants;
	
	ants = malloc(config->number_of_ants * sizeof(t_ant));
	if (ants == NULL)
	{
		ft_putstr_fd("Failed to allocate memory for ants.\n", STDERR_FILENO);
		return (1);
	}
	initialize_ants(ants, config->number_of_ants);
	//printf("path_count: %d\n", path_count);
	//printf("config->number_of_ants: %d\n", config->number_of_ants);
	//printf("config->end_room_id: %d\n", config->end_room_id);
	distribute_ants(&paths, path_count, config->number_of_ants, ants);
	move_ants(&paths, ants, config->number_of_ants, config->end_room_id);
	free(ants);
	return (1);
}
