#include "../includes/lem_in.h"


int bfs_with_ant(t_room *rooms, t_link *links, int startRoomId, int endRoomId)
{
    t_path *paths = NULL;
    int room_count = 0;
    t_room *tmp = rooms;
    while (tmp)
    {
        tmp = tmp->next;
        room_count++;
    }

    int visited[room_count];
    memset(visited, 0, sizeof(visited));

    int *queue = malloc(room_count * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = startRoomId;
    visited[startRoomId] = 1;

    while (front < rear)
    {
        int uId = queue[front++];
        if (uId == endRoomId)
        {
            paths = add_path(&paths, queue, rear);
            break;
        }
        for (t_link *link = links; link; link = link->next)
        {
            printf("link->startId: %d, uId: %d, visited[link->endId]: %d\n", link->startId, uId, visited[link->endId]);
            if (link->startId == uId && !visited[link->endId])
            {
                queue[rear++] = link->endId;
                visited[link->endId] = 1;
            }
        }
    }
    printf("paths->path[0]: %d, paths->path[1]: %d\n", paths->path[0], paths->path[1]);
    free_paths(&paths);
    return 0;
}

