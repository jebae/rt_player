#include "rt_player.h"

static void		event_object_rotate(
	float theta,
	t_dispatcher *dispatcher
)
{
	char		*objects_buf;
	t_vec4		n;

	objects_buf = select_object(
		dispatcher->settings->objects_buf, dispatcher->object_index);
	n = camera_z_axis(&(dispatcher->settings->cam));
	object_rotate(objects_buf, &n, theta);
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
