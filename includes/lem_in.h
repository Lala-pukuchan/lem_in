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
}					t_link;

typedef struct s_path
{
	int				*room_ids;
	int				room_count;
	struct s_path	*next;
}					t_path;

void				free_rooms(t_room **rooms);
void				free_links(t_link **links);
t_room				*add_room(t_room **rooms, char *name, int x, int y,
						int is_start, int is_end);
void				add_link(t_link **links, char *start, char *end,
						t_room *rooms);
int					check(int number_of_ants, t_room *rooms, t_link *links,
						int startFlag, int endFlag);
int					bfs_with_ant(t_room *rooms, t_link *links, int startRoomId,
						int endRoomId);
int					get_room_index(t_room *rooms, char *name);
t_path				*add_path(t_path **paths, int *queue, int queue_size);
void				free_paths(t_path **paths);

#endif
