#include "../includes/lem_in.h"

void exist_start_end(t_room *rooms)
{
    t_room *current = rooms;
    int start = 0;
    int end = 0;
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
        printf("Invalid number of start or end.\n");
        exit(1);
    }
}

void exit_pass(t_room *rooms, t_link *links)
{
    (void)rooms;
    (void)links;
}

int check_solution(t_room *rooms, t_link *links)
{
    exist_start_end(rooms);
    exit_pass(rooms, links);
    return 0;
}

int check(int number_of_ants, t_room *rooms, t_link *links, int startFlag, int endFlag)
{
    if (startFlag == 0 || endFlag == 0)
    {
        printf("No start or end.\n");
        return 1;
    }
    printf("Checking...%d\n", number_of_ants);
    if (number_of_ants <= 0 || number_of_ants > INT_MAX)
    {
        printf("Invalid number of ants.\n");
        return 1;
    }
    if (rooms == NULL || links == NULL)
    {
        printf("Invalid room or link.\n");
        return 1;
    }
    return check_solution(rooms, links);
}