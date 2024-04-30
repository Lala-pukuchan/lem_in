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

void	process_comment_line(char *input, t_simulation_config *config)
{
	if (ft_strncmp(input, "##start", 7) == 0)
	{
		config->start_flag = 1;
		config->state = 1;
	}
	else if (ft_strncmp(input, "##end", 5) == 0)
		config->end_flag = 1;
}

void	process_ant_count(char *input, t_simulation_config *config)
{
	config->number_of_ants = ft_atoi(input);
	if (config->number_of_ants <= 0)
	{
		ft_putstr_fd("Invalid number of ants.\n", STDERR_FILENO);
		exit(1);
	}
	config->state = 1;
}

void	process_room_line(char *input, \
	t_simulation_config *config, t_room **rooms)
{
	t_r_info	room_info;

	room_info.name = ft_strtok(input, " ");
	room_info.x = ft_atoi(ft_strtok(NULL, " "));
	room_info.y = ft_atoi(ft_strtok(NULL, " "));
	if (config->start_flag == 1)
	{
		*rooms = add_room(rooms, &room_info, 1, 0);
		config->start_room_id = (*rooms)->id;
		(config->start_flag)++;
	}
	else if (config->end_flag == 1)
	{
		*rooms = add_room(rooms, &room_info, 0, 1);
		config->end_room_id = (*rooms)->id;
		(config->end_flag)++;
	}
	else
		*rooms = add_room(rooms, &room_info, 0, 0);
}

void	process_link_line(char *input, t_link **links, t_room *rooms)
{
	char	*start;
	char	*end;

	start = ft_strtok(input, "-");
	end = ft_strtok(NULL, "-");
	add_link(links, start, end, rooms);
}

void	parse_input(char *input, t_simulation_config *config, t_room **rooms, \
	t_link **links)
{
	input[strcspn(input, "\n")] = 0;
	if (input[0] == '#')
	{
		process_comment_line(input, config);
		return ;
	}
	if (config->state == 0)
	{
		process_ant_count(input, config);
		return ;
	}
	else if (config->state == 1)
	{
		if (ft_strchr(input, '-') != NULL)
			config->state = 2;
		else
			process_room_line(input, config, rooms);
	}
	if (config->state == 2)
	{
		process_link_line(input, links, *rooms);
	}
}
