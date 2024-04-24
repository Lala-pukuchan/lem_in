#ifndef LEM_IN_H
# define LEM_IN_H

# define MAX_INPUT_SIZE 256

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_room
{
	int id; // New field for room ID
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
	int path_index;       // Index of the path this ant is on
	int current_position; // Index of the current room in the path
}					t_ant;

void				free_rooms(t_room **rooms);
void				free_links(t_link **links);
t_room				*add_room(t_room **rooms, char *name, int x, int y,
						int is_start, int is_end);
void				add_link(t_link **links, char *start, char *end,
						t_room *rooms);
int					check(int number_of_ants, t_room *rooms, t_link *links,
						int startFlag, int endFlag);
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

#endif
