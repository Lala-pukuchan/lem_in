/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rukobaya < rukobaya@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:24:34 by rukobaya          #+#    #+#             */
/*   Updated: 2024/04/18 20:14:15 by rukobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lem_in.h"

int main() {
    char input[MAX_INPUT_SIZE];
    int number_of_ants = -1;
    t_room *rooms = NULL;
    t_link *links = NULL;
    int state = 0;
    int startFlag = 0;
    int endFlag = 0;

    char *startRoomName = NULL;
    char *endRoomName = NULL;

    while (fgets(input, MAX_INPUT_SIZE, stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;

        if (input[0] == '#') {
            if (ft_strncmp(input, "##start", 6) == 0) {
                startFlag = 1;
                state = 1;
                continue;
            } else if (ft_strncmp(input, "##end", 4) == 0) {
                endFlag = 1;
                continue;
            }
            continue;
        }

        if (state == 0) {
            number_of_ants = ft_atoi(input);
            if (number_of_ants <= 0) {
                printf("Invalid number of ants.\n");
                return 1;
            }
            state = 1;
        } else if (state == 1) {
            if (strchr(input, '-') != NULL) {
                state = 2;
            } else {
                char *name = strtok(input, " ");
                int x = ft_atoi(strtok(NULL, " "));
                int y = ft_atoi(strtok(NULL, " "));
                if (startFlag == 1) {
                    rooms = add_room(&rooms, name, x, y, 1, 0);
                    startRoomName = ft_strdup(name);
                    startFlag++;
                } else if (endFlag == 1) {
                    rooms = add_room(&rooms, name, x, y, 0, 1);
                    endRoomName = ft_strdup(name);
                    endFlag++;
                } else {
                    rooms = add_room(&rooms, name, x, y, 0, 0);
                }
                continue;
            }
        }
        if (state == 2) {
            char *start = strtok(input, "-");
            char *end = strtok(NULL, "-");
            links = add_link(&links, start, end, rooms);
        }
    }

    if (ferror(stdin)) {
        printf("Error reading input.\n");
        return 1;
    }

    int res = check(number_of_ants, rooms, links, startFlag, endFlag);
    if (res == 1) {
        free_rooms(&rooms);
        free_links(&links);
        printf("Invalid ant farm.\n");
        return 1;
    }

    for (t_room *room = rooms; room != NULL; room = room->next) {
        printf("struct Room: %s %d %d %d %d %d\n", room->name, room->x, room->y, room->is_start, room->is_end, room->id);
    }
    for (t_link *link = links; link != NULL; link = link->next) {
        printf("struct Link: %s %s %d %d\n", link->start, link->end, link->startId, link->endId);
    }



    //bfs_with_ant(rooms, links, startRoomName, endRoomName, NULL, NULL);

    free_rooms(&rooms);
    free_links(&links);
    free(startRoomName);
    free(endRoomName);

    system("leaks lem-in");

    return 0;
}
