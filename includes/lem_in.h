#ifndef LEM_IN_H
# define LEM_IN_H

# define MAX_INPUT_SIZE 256
# define MAX_ROOM_SIZE 10000

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
extern char			**g_room_names;

typedef struct s_room
{
	int				id;
	char			*name;
	int x, y;
	int				is_start;
	int				is_end;
	struct s_room	*next;
}					t_room;

typedef struct s_link
{
	int				startId;
	int				endId;
	struct s_link	*next;
	bool			opposite;
}					t_link;

typedef struct s_path
{
	int				*room_ids;
	int				room_count;
	struct s_path	*next;
}					t_path;

typedef struct s_ant
{
	int				ant_id;
	int				path_index;
	int				current_position;
}					t_ant;

typedef struct s_ant_move_params 
{
    t_ant			*ant;
    t_path			*path;
    int				*rooms;
    bool			*arrived;
    int				end_room_id;
}					t_ant_move_params;

typedef struct 		s_distribution
{
    t_path			**paths;
    int				*ants_in_path;
    int				num_paths;
}					t_distribution;

typedef struct s_ant_movement {
    t_ant *ant;
    int *rooms;
    bool *arrived;
    int end_room_id;
} t_ant_movement;

typedef struct		s_movement_context
{
	t_path			**paths;
	t_ant			*ants;
	int				*rooms;
	bool			*arrived;
	bool			*moved;
	int				num_ants;
	int				end_room_id;
}					t_movement_context;

typedef struct s_movement
{
	t_path			**paths;
	t_ant			*ants;
	int				*rooms;
	bool			*arrived;
	bool			*moved;
	int				num_ants;
	int				end_room_id;
}					t_movement;

typedef struct s_find_path_params {
    t_link *links;
    int startRoomId;
    int endRoomId;
    t_path **paths;
    int room_count;
    int *visited;
    int *queue;
    int *predecessors;
    int front;
    int rear;
} t_find_path_params;

typedef struct s_link_info {
    char *start;
    char *end;
    t_room *rooms;
} t_link_info;
typedef struct {
    int number_of_ants;
    t_room *rooms;
    t_link *links;
    int startFlag;
    int endFlag;
    int startRoomId;
    int endRoomId;
} t_main_data;

typedef struct {
    int state;
    int startFlag;
    int endFlag;
    int startRoomId;
    int endRoomId;
    int number_of_ants;
} SimulationConfig;


void				free_rooms(t_room **rooms);
void				free_links(t_link **links);
t_room				*add_room(t_room **rooms, char *name, int x, int y,
						int is_start, int is_end);
void				add_link(t_link **links, char *start, char *end,
						t_room *rooms);
int					check_ants(int number_of_ants, t_room *rooms, t_link *links);
int					check_flags(t_room *rooms, t_link *links, int startFlag, int endFlag);
t_path				*bfs_with_ant(t_room *rooms, t_link *links, int startRoomId,
						int endRoomId);
int					get_room_index(t_room *rooms, char *name);
t_path				*add_path(t_path **paths, int *queue, int queue_size);
void				free_paths(t_path **paths);
void				output_details(int number_of_ants, t_room *rooms_head,
						t_link *links_head);
void				reverse_paths(t_path **paths);
void				distribute_ants(t_path **paths, int num_paths, int num_ants,
						t_ant *ants);
void				move_ants(t_path **paths, t_ant *ants, int num_ants,
						int end_room_id);
void				initialize_room_names(int num_rooms);
void				free_room_names(void);
t_path				*find_path_for_ant(t_path **paths, int path_index);
void				move_ant(t_ant_move_params *params, bool *moved);
int					find_best_path(t_distribution *dist);
void				initialize_movement(int num_ants, int **rooms, bool **arrived);
void				process_ants_movement(t_movement_context *context);
int					*create_empty_rooms(int room_count);

//1_edmondskarp.c
int					*create_empty_visited(int room_count, int startRoomId);
void				update_visited(int *visited, t_path *paths, \
						int room_count, int endRoomId);
int					initialize_find_path_params(t_find_path_params *params);
int					calculate_path_length(int *predecessors, int endRoomId);
int					*construct_path(int *predecessors, int path_length, int endRoomId);
//2_edmondskarp.c
void				add_path_to_paths(t_path **paths, int *path, int path_length);
void				update_queue_and_predecessors(t_find_path_params *params, int uId);
int					process_node(t_find_path_params *params, int uid);
int					find_path(t_find_path_params *params);
bool				exist_second_step(t_link *links, int startRoomId, int *visited);
//3_edmondskarp.c
void				initialize_params(t_find_path_params *params, t_room *rooms);
t_path				*execute_search(t_find_path_params *params, \
						t_link *links, int startRoomId);
t_path				*bfs_with_ant(t_room *rooms, t_link *links, \
						int startRoomId, int endRoomId);
#endif
