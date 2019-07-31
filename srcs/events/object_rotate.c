#include "rt_player.h"

static void		event_object_rotate(
	float theta,
	t_dispatcher *dispatcher
)
{
	char		*objects_buf;

	objects_buf = select_object(
		dispatcher->settings->objects_buf, dispatcher->object_index);
	object_rotate(objects_buf, &(dispatcher->settings->cam.z_axis), theta);
	render_by_mlx(dispatcher);
}

void			key_comma(t_dispatcher *dispatcher)
{
	event_object_rotate(DEGREE_1 * 10.0f, dispatcher);
}

void			key_point(t_dispatcher *dispatcher)
{
	event_object_rotate(DEGREE_1 * -10.0f, dispatcher);
}
