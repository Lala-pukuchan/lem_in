#include "../includes/lem_in.h"

t_path *add_path(t_path **paths, int *queue, int queue_size)
{
    t_path *new_path = malloc(sizeof(t_path));
    if (new_path == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_path->room_ids = malloc(queue_size * sizeof(int));
    memcpy(new_path->room_ids, queue, queue_size * sizeof(int));
    new_path->room_count = queue_size;
    new_path->next = *paths;
    *paths = new_path;
    return new_path;
}

void free_paths(t_path **paths)
{
    t_path *current = *paths;
    while (current != NULL) {
        t_path *next = current->next;
        free(current->room_ids);
        free(current);
        current = next;
    }
    *paths = NULL;
}