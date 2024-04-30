/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsujimariko <mtsuji@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:38:39 by tsujimari         #+#    #+#             */
/*   Updated: 2024/04/30 16:38:41 by tsujimari        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
extern int			g_room_count;

typedef struct s_room
{
	int				id;
	char			*name;
	int				x;
	int				y;
	int				is_start;
	int				is_end;
	struct s_room	*next;
}					t_room;

typedef struct s_link
{
	int				start_id;
	int				end_id;
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
typedef struct s_distribution
{
	t_path			**paths;
	int				*ants_in_path;
	int				num_paths;
}					t_distribution;

typedef struct s_ant_movement
{
	t_ant			*ant;
	int				*rooms;
	bool			*arrived;
	int				end_room_id;
}					t_ant_movement;

typedef struct s_movement_context
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

typedef struct s_find_path_params
{
	t_link			*links;
	int				start_room_id;
	int				end_room_id;
	t_path			**paths;
	int				room_count;
	int				*visited;
	int				*queue;
	int				*predecessors;
	int				front;
	int				rear;
}					t_find_path_params;

typedef struct s_link_info
{
	char			*start;
	char			*end;
	t_room			*rooms;
}					t_link_info;
typedef struct s_main_data
{
	int				number_of_ants;
	t_room			*rooms;
	t_link			*links;
	int				start_flag;
	int				end_flag;
	int				start_room_id;
	int				end_room_id;
}				t_main_data;

typedef struct s_simulation_config
{
	int				state;
	int				start_flag;
	int				end_flag;
	int				start_room_id;
	int				end_room_id;
	int				number_of_ants;
}				t_simulation_config;
typedef struct s_r_info
{
	char			*name;
	int				x;
	int				y;
}				t_r_info;

//1_edmondskarp.c
int					*create_empty_visited(int room_count, int start_room_id);
void				update_visited(int *visited, t_path *paths, \
						int room_count, int end_room_id);
int					initialize_find_path_params(t_find_path_params *params);
int					calculate_path_length(int *predecessors, int end_room_id);
int					*construct_path(int *predecessors, int path_length, \
						int end_room_id);
//2_edmondskarp.c
void				add_path_to_paths(t_path **paths, int *path, \
						int path_length);
void				update_queue_and_predecessors(t_find_path_params *params, \
						int uId);
int					process_node(t_find_path_params *params, int uid);
int					find_path(t_find_path_params *params);
bool				exist_second_step(t_link *links, int start_room_id, \
						int *visited);
//3_edmondskarp.c
void				initialize_params(t_find_path_params *params, \
						t_room *rooms);
t_path				*execute_search(t_find_path_params *params, \
						t_link *links, int start_room_id);
t_path				*bfs_with_ant(t_room *rooms, t_link *links, \
						int start_room_id, int end_room_id);
//1_outil_for_main
void				process_comment_line(char *input, \
						t_simulation_config *config);
void				process_ant_count(char *input, t_simulation_config *config);
void				process_room_line(char *input, \
						t_simulation_config *config, t_room **rooms);
void				process_link_line(char *input, t_link **links, \
						t_room *rooms);
void				parse_input(char *input, t_simulation_config *config, \
						t_room **rooms, t_link **links);
//2_outil_for_main
void				free_resources(t_ant *ants, t_room *rooms, \
						t_link *links, t_path *paths);
int					validate_ants_number(int number_of_ants, t_room *rooms, \
						t_link *links);
int					validate_flags(t_room *rooms, t_link *links, \
						int start_flag, int end_flag);
void				initialize_ants(t_ant *ants, int number_of_ants);
int					count_paths(t_path *paths);
//3_outil_for_main
void				initialize_simulation_config(t_simulation_config *config);
void				read_and_parse_input(t_simulation_config *config, \
						t_room **rooms, t_link **links);
void				finalize_simulation(t_room *rooms, t_link *links);
t_path				*setup_simulation(t_simulation_config *config, \
						t_room *rooms, t_link *links, int *path_count);
int					run_simulation(t_path *paths, int path_count, \
						t_simulation_config *config);
//ant.c
int					find_best_path(t_distribution *dist);
void				distribute_ants(t_path **paths, int num_paths, \
						int num_ants, t_ant *ants);
int					*create_empty_rooms(int room_count);
void				move_ant(t_ant_move_params *params, bool *moved);
t_path				*find_path_for_ant(t_path **paths, int path_index);
//check.c
void				exist_start_end(t_room *rooms);
int					check_solution(t_room *rooms);
int					check_ants(int number_of_ants, t_room *rooms, \
						t_link *links);
int					check_flags(t_room *rooms, t_link *links, \
						int start_flag, int end_flag);
//link.c
int					get_room_id(t_room *rooms, char *name);
t_link				*add_link_both_order(t_link **links, \
						t_link_info *info, bool opposite);
void				add_link(t_link **links, char *start, \
						char *end, t_room *rooms);
void				free_links(t_link **links);
//movement_ant.c;
void				initialize_movement(int num_ants, int **rooms, \
						bool **arrived);
void				move_single_ant(t_path **paths,
						t_ant_movement *move_params, bool *moved);
void				process_ants_movement(t_movement_context *context);
void				cleanup_movement_resources(int *rooms, bool *arrived);
void				move_ants(t_path **paths, t_ant *ants, \
						int num_ants, int end_room_id);
//path.c
t_path				*add_path(t_path **paths, int *queue, int queue_size);
void				free_paths(t_path **paths);
void				reverse_paths(t_path **paths);
//print.c
void				print_start_room(t_room *rooms_head);
void				print_end_room(t_room *rooms_head);
void				output_details(int number_of_ants, t_room *rooms_head,
						t_link *links_head);
//room.c
void				initialize_room_names(int num_rooms);
t_room				*add_room(t_room **rooms, t_r_info *room_info, \
						int is_start, int is_end);
void				free_rooms(t_room **rooms);
void				free_room_names(void);
#endif