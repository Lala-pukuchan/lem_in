#include "../includes/lem_in.h"


void distribute_ants(t_path **paths, int num_paths, int num_ants, t_ant *ants) {
    int *ants_in_path = calloc(num_paths, sizeof(int)); // Track ants in each path
    for (int i = 0; i < num_ants; i++) {
        int best_path = 0;
        for (int j = 1; j < num_paths; j++) {
            if (paths[j]->room_count + ants_in_path[j] < paths[best_path]->room_count + ants_in_path[best_path]) {
                best_path = j;
            }
        }
        ants_in_path[best_path]++;
        ants[i].ant_id = i + 1;
        ants[i].path_index = best_path;
    }
    free(ants_in_path);
}
void move_ants(t_path **paths, int num_paths, t_ant *ants, int num_ants) {
    bool moved = true;
    (void)num_paths;
    while (moved) {
        moved = false;
        for (int i = 0; i < num_ants; i++) {
            t_ant *ant = &ants[i];
            t_path *path = paths[ant->path_index];
            // Assuming we have a way to track the current position of each ant in its path.
            // For simplicity, let's say it's the index in the path's room_ids array.
            int next_room_index = ant->current_position + 1;
            if (next_room_index < path->room_count) {
                printf("L%d-%d ", ant->ant_id, path->room_ids[next_room_index]);
                ant->current_position = next_room_index;
                moved = true;
            }
        }
        printf("\n"); // End of a "turn"
    }
}