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

char	**g_room_names = NULL;

int	main(void)
{
	t_room				*rooms;
	t_link				*links;
	t_simulation_config	config;
	t_path				*paths;
	int					path_count;

	rooms = NULL;
	links = NULL;
	initialize_room_names(MAX_ROOM_SIZE);
	initialize_simulation_config(&config);
	read_and_parse_input(&config, &rooms, &links);
	if (validate_ants_number(config.number_of_ants, rooms, links) != 0 || \
		validate_flags(rooms, links, config.start_flag, config.end_flag) != 0)
		return (free_resources(rooms, links, NULL), 1);
	paths = setup_simulation(&config, rooms, links, &path_count);
	if (!run_simulation(paths, path_count, &config))
		return (finalize_simulation(rooms, links, paths), 1);
	finalize_simulation(rooms, links, paths);
	printf("g_room_count: %d\n", g_room_count);
	return (0);
}
