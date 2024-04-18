#include "../includes/lem_in.h"

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
    return 0;
}