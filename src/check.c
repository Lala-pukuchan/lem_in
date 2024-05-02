/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:52:54 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/29 15:52:58 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exist_start_end(t_room *rooms)
{
	t_room	*current;
	int		start;
	int		end;

	current = rooms;
	start = 0;
	end = 0;
	while (current != NULL)
	{
		if (current->is_start == 1)
			start++;
		if (current->is_end == 1)
			end++;
		current = current->next;
	}
	if (start != 1 || end != 1)
	{
		ft_printf("Invalid number of start or end.\n");
		exit(1);
	}
}

int	check_solution(t_room *rooms)
{
	exist_start_end(rooms);
	return (0);
}

int	check_ants(int number_of_ants, t_room *rooms, t_link *links)
{
	if (number_of_ants <= 0 || number_of_ants > INT_MAX)
	{
		ft_printf("Invalid number of ants.\n");
		return (1);
	}
	if (rooms == NULL || links == NULL)
	{
		ft_printf("Invalid room or link.\n");
		return (1);
	}
	return (check_solution(rooms));
}

int	check_flags(t_room *rooms, t_link *links, int start_flag, int end_flag)
{
	if (start_flag == 0 || end_flag == 0)
	{
		ft_printf("No start or end.\n");
		return (1);
	}
	if (rooms == NULL || links == NULL)
	{
		ft_printf("Invalid room or link.\n");
		return (1);
	}
	return (check_solution(rooms));
}
