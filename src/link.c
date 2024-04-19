#include "../includes/lem_in.h"

int	getRoomId(t_room *rooms, char *name)
{
	int		id;
	t_room	*current;

	id = 0;
	current = rooms;
	while (current != NULL)
	{
		if (strcmp(current->name, name) == 0)
		{
			id = current->id;
		}
		current = current->next;
	}
	return (id);
}

t_link	*add_link_both_order(t_link **links, char *start, char *end, t_room *rooms)
{
	t_link	*new_link;

	new_link = malloc(sizeof(t_link));
	if (new_link == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	new_link->startId = getRoomId(rooms, start);
	new_link->endId = getRoomId(rooms, end);
	new_link->next = *links;
	*links = new_link;
	return (new_link);
}

void add_link(t_link **links, char *start, char *end, t_room *rooms)
{
	add_link_both_order(links, start, end, rooms);
	add_link_both_order(links, end, start, rooms);
}

void	free_links(t_link **links)
{
	t_link	*current;
	t_link	*next;

	current = *links;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*links = NULL;
}
