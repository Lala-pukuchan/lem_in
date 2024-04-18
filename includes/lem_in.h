#ifndef LEM_IN_H
# define LEM_IN_H

#define MAX_INPUT_SIZE 256


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "../libft/libft.h"


typedef struct s_room {
    char *name;
    int x, y;
    int is_start;
    int is_end;
    struct s_room *next;
} t_room;

typedef struct s_link {
    char *start;
    char *end;
    struct s_link *next;
} t_link;


void free_rooms(t_room **rooms);
void free_links(t_link **links);
t_room *add_room(t_room **rooms, char *name, int x, int y, int is_start, int is_end);
t_link *add_link(t_link **links, char *start, char *end);
int check(int number_of_ants, t_room *rooms, t_link *links, int startFlag, int endFlag);
#endif

