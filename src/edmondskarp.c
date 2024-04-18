#include "../includes/lem_in.h"

int bfs_with_ant(t_room *rooms, t_link *links, char *s, char *t, char ***paths, int *path_count)
{
    (void)rooms;
    (void)links;
    (void)s;
    (void)t;
    (void)paths;
    (void)path_count;

    int room_count = 0;
    t_room *tmp = rooms;
    while (tmp)
    {
        tmp = tmp->next;
        room_count++;
    }

    int visited[room_count];
    memset(visited, 0, sizeof(visited));

    char **queue = malloc(room_count * sizeof(char *));
    printf("room_count: %d\n", room_count);
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[get_room_index(rooms, s)] = 1;

    (void)queue;
    (void)front;
    (void)rear;
    (void)visited;

    while (front < rear)
    {
        char *u = queue[front++];
        if (!strcmp(u, t))
        {
            save_path(paths, path_count, queue, front);
            break;
        }
        for (t_link *link = links; link; link = link->next) {
            // `u`がリンクの始点の場合、そのリンクの終点へ進む
            if (strcmp(link->start, u) == 0 && !visited[get_room_index(rooms, link->end)]) {
                printf("rear: %d %s\n", rear, link->end);
                queue[rear++] = link->end;
                visited[get_room_index(rooms, link->end)] = 1;
            }
            //// `u`がリンクの終点の場合、そのリンクの始点へ戻る（逆戻りを許容する場合）
            //else if (strcmp(link->end, u) == 0 && !visited[get_room_index(rooms, link->start)]) {
            //    queue[rear++] = link->start;
            //    visited[get_room_index(rooms, link->start)] = 1;
            //}
        }

    }
    free(queue);
    return 0;
}

void save_path(char ***paths, int *path_count, char **queue, int queue_size)
{
    paths[*path_count] = malloc(queue_size * sizeof(char *));
    for (int i = 0; i < queue_size; i++)
    {
        paths[*path_count][i] = strdup(queue[i]);
    }
    (*path_count)++;
}

int get_room_index(t_room *rooms, char *name)
{
    int index = 0;
    for (t_room *tmp = rooms; tmp; tmp = tmp->next, index++)
    {
        if (strcmp(tmp->name, name) == 0)
        {
            return index;
        }
    }
    return -1;
}
