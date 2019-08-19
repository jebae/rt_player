#include "animator_test.h"

static void		event_camera_rotate(t_test_dispatcher *dispatcher)
{
	dispatcher->settings->ray_grid_props = get_ray_grid_properties(
		&(dispatcher->cam),
		(float)(dispatcher->settings->window_width),
		(float)(dispatcher->settings->window_height),
		M_PI / 2.0f);
	event_render(dispatcher);
}

void			key_j(void *param)
{
	t_test_dispatcher	*dispatcher;

	dispatcher = (t_test_dispatcher *)param;
	rotate_camera_pan(&(dispatcher->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_l(void *param)
{
	t_test_dispatcher	*dispatcher;

	dispatcher = (t_test_dispatcher *)param;
	rotate_camera_pan(&(dispatcher->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_i(void *param)
{
	t_test_dispatcher	*dispatcher;

	dispatcher = (t_test_dispatcher *)param;
	rotate_camera_tilt(&(dispatcher->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_k(void *param)
{
	t_test_dispatcher	*dispatcher;

	dispatcher = (t_test_dispatcher *)param;
	rotate_camera_tilt(&(dispatcher->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}
