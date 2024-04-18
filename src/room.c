#include "../includes/lem_in.h"

t_room *add_room(t_room **rooms, char *name, int x, int y)
{
    t_room *new_room = malloc(sizeof(t_room));
    if (new_room == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_room->name = strdup(name);
    new_room->x = x;
    new_room->y = y;
    new_room->next = *rooms;
    *rooms = new_room;
    return new_room;
}

void free_rooms(t_room **rooms)
{
    t_room *current = *rooms;
    while (current != NULL) {
        t_room *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    *rooms = NULL;
}