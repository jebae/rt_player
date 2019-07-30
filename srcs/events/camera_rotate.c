#include "rt_player.h"

static void		event_camera_rotate(t_dispatcher *dispatcher)
{
	set_rt_global_settings_ray_grid_props(
		dispatcher->settings,
		&(dispatcher->settings->cam)
	);
	render_by_mlx(dispatcher);
}

void			key_j(t_dispatcher *dispatcher)
{
	rotate_camera_pan(&(dispatcher->settings->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_l(t_dispatcher *dispatcher)
{
	rotate_camera_pan(&(dispatcher->settings->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_i(t_dispatcher *dispatcher)
{
	rotate_camera_tilt(&(dispatcher->settings->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_k(t_dispatcher *dispatcher)
{
	rotate_camera_tilt(&(dispatcher->settings->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}
