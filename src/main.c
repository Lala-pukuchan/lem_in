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
void parse_input(char *input, SimulationConfig *config, t_room **rooms, \
	t_link **links) {
    input[strcspn(input, "\n")] = 0; // Remove newline character
    if (input[0] == '#') {
        if (ft_strncmp(input, "##start", 7) == 0) {
            config->startFlag = 1;
            config->state = 1;
            return;
        } else if (ft_strncmp(input, "##end", 5) == 0) {
            config->endFlag = 1;
            return;
        }
        return;
    }
    if (config->state == 0) {
        config->number_of_ants = atoi(input);
        if (config->number_of_ants <= 0)
		{
            printf("Invalid number of ants.\n");
            exit(1);
        }
        config->state = 1;
    } else if (config->state == 1) {
        if (ft_strchr(input, '-') != NULL) {
            config->state = 2;
        } else {
            char *name = ft_strtok(input, " ");
            int x = atoi(ft_strtok(NULL, " "));
            int y = atoi(ft_strtok(NULL, " "));
            if (config->startFlag == 1) {
                *rooms = add_room(rooms, name, x, y, 1, 0);
                config->startRoomId = (*rooms)->id;
                (config->startFlag)++;
            } else if (config->endFlag == 1) {
                *rooms = add_room(rooms, name, x, y, 0, 1);
                config->endRoomId = (*rooms)->id;
                (config->endFlag)++;
            } else {
                *rooms = add_room(rooms, name, x, y, 0, 0);
            }
            return ;
        }
    }
    if (config->state == 2) {
        char *start = ft_strtok(input, "-");
        char *end = ft_strtok(NULL, "-");
        add_link(links, start, end, *rooms);
    }
}

void free_resources(t_ant *ants, t_room *rooms, t_link *links, t_path *paths) {
    if (ants != NULL)
		free(ants);
	if (rooms != NULL)
    	free_rooms(&rooms);
    if (links != NULL)
		free_links(&links);
    if (paths != NULL)
		free_paths(&paths);
}

int validate_ants_number(int number_of_ants, t_room *rooms, t_link *links) {
    if (check_ants(number_of_ants, rooms, links) != 0)
        return (printf("Invalid number of ants.\n"), 1);
    return 0;
}

int validate_flags(t_room *rooms, t_link *links, int startFlag, int endFlag) {
    if (check_flags(rooms, links, startFlag, endFlag) != 0)
        return (printf("Invalid flag configuration.\n"), 1);
    return 0;
}

void initialize_ants(t_ant *ants, int number_of_ants)
{
	int i;

	i = 0;
    while (i < number_of_ants) {
        ants[i].ant_id = i + 1;
        ants[i].path_index = -1;
        ants[i].current_position = 0;
		i++;
    }
}
int count_paths(t_path *paths)
{
    int count = 0;
    while (paths) {
        paths = paths->next;
        count++;
    }
    return count;
}

void initialize_simulation_config(SimulationConfig *config) {
    config->state = 0;
    config->startFlag = 0;
    config->endFlag = 0;
    config->startRoomId = -1;
    config->endRoomId = -1;
    config->number_of_ants = -1;
}

int main(void) {
    char *input;
    t_room *rooms = NULL;
    t_link *links = NULL;
	SimulationConfig config;
    t_path *paths;
    int pathCount;
    t_ant *ants;

    initialize_room_names(MAX_ROOM_SIZE);
	initialize_simulation_config(&config);
    while ((input = get_next_line(STDIN_FILENO)) != NULL) {
        parse_input(input, &config, &rooms, &links);
        free(input);
    }
    if (validate_ants_number(config.number_of_ants, rooms, links) != 0 || 
        validate_flags(rooms, links, config.startFlag, config.endFlag) != 0)
        return (free_resources(NULL, rooms, links, NULL), 1);
    paths = bfs_with_ant(rooms, links, config.startRoomId, config.endRoomId);
    reverse_paths(&paths);
    pathCount = count_paths(paths);
    output_details(config.number_of_ants, rooms, links);
    ants = malloc(config.number_of_ants * sizeof(t_ant));
    if (ants == NULL)
        return (fprintf(stderr, "Failed to allocate memory for ants.\n"), 1);
	initialize_ants(ants, config.number_of_ants);
    distribute_ants(&paths, pathCount, config.number_of_ants, ants);
    move_ants(&paths, ants, config.number_of_ants, config.endRoomId);
	free_resources(ants, rooms, links, paths);
    free_room_names();
    return (0);
}
