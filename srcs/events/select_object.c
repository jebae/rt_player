#include "rt_player.h"

void		key_left_bracket(t_dispatcher *dispatcher)
{
	if (dispatcher->object_index == 0)
	{
		dispatcher->object_index = dispatcher->settings->num_objects - 1;
		return ;
	}
	(dispatcher->object_index)--;
}

void		key_right_bracket(t_dispatcher *dispatcher)
{
	(dispatcher->object_index)++;
	dispatcher->object_index %= dispatcher->settings->num_objects;
}
