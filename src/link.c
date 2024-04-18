#include "../includes/lem_in.h"

t_link *add_link(t_link **links, char *start, char *end)
{
    t_link *new_link = malloc(sizeof(t_link));
    if (new_link == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_link->start = strdup(start);
    new_link->end = strdup(end);
    new_link->next = *links;
    *links = new_link;
    return new_link;
}



void free_links(t_link **links)
{
    t_link *current = *links;
    while (current != NULL) {
        t_link *next = current->next;
        free(current->start);
        free(current->end);
        free(current);
        current = next;
    }
    *links = NULL;
}
