/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:34:17 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/19 15:49:59 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void print_start_room(t_room *rooms_head) {
    t_room *current_room = rooms_head;
    while (current_room != NULL) {
        if (current_room->is_start) {
            printf("##start\n");
            printf("%d %d %d\n", current_room->id, current_room->x, current_room->y);
            return; // Exit after printing the start room
        }
        current_room = current_room->next;
    }
}

void print_end_room(t_room *rooms_head) {
    t_room *current_room = rooms_head;
    while (current_room != NULL) {
        if (current_room->is_end) {
            printf("##end\n");
            printf("%d %d %d\n", current_room->id, current_room->x, current_room->y);
            return; // Exit after printing the end room
        }
        current_room = current_room->next;
    }
}

void output_details(int number_of_ants, t_room *rooms_head, t_link *links_head) {
    t_room *current_room;
    t_link *current_link;

    printf("%d\n", number_of_ants);
    print_start_room(rooms_head);
    print_end_room(rooms_head);

    current_room = rooms_head;
    // Now, print the rest of the rooms, skipping the start and end rooms
    while (current_room != NULL) {
        if (!current_room->is_start && !current_room->is_end) {
            printf("%d %d %d\n", current_room->id, current_room->x, current_room->y);
        }
        current_room = current_room->next; // Move to the next room in the list
    }
    current_link = links_head;
    while (current_link != NULL) {
        if (!current_link->opposite) {
            printf("%d-%d\n", current_link->startId, current_link->endId);
        }
        current_link = current_link->next; // Move to the next link in the list
    }
}
