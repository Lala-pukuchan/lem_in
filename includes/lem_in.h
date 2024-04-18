#ifndef LEM_IN_H
# define LEM_IN_H

#define MAX_INPUT_SIZE 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "../libft/libft.h"


typedef struct s_room {
    int id; // New field for room ID
    char *name;
    int x, y;
    int is_start;
    int is_end;
    struct s_room *next;
} t_room;

typedef struct s_link {
    char *start; // Consider renaming to startName if you keep both name and ID
    char *end;   // Consider renaming to endName
    int startId; // New field for start room ID
    int endId;   // New field for end room ID
    struct s_link *next;
} t_link;


void free_rooms(t_room **rooms);
void free_links(t_link **links);
t_room *add_room(t_room **rooms, char *name, int x, int y, int is_start, int is_end);
t_link *add_link(t_link **links, char *start, char *end, t_room *rooms);
int check(int number_of_ants, t_room *rooms, t_link *links, int startFlag, int endFlag);
int bfs_with_ant(t_room *rooms, t_link *links, char *s, char *t, char ***paths, int *path_count);
void save_path(char ***paths, int *path_count, char **queue, int queue_size);
int get_room_index(t_room *rooms, char *name);

#endif

