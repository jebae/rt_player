#include "rt_player.h"

t_global_settings		init_rt_global_settings(
	t_dispatcher *dispatcher,
	float width,
	float height
)
{
	static t_vec4		i_a = (t_vec4){{0.05f, 0.05f, 0.05f, 1.0f}};
	t_global_settings	settings;

	settings.parallel_mode = dispatcher->parallel_mode;
	settings.window_width = (int)width;
	settings.window_height = (int)height;
	settings.i_a = i_a;
	settings.img_buf = (int *)get_img_buffer(
		dispatcher->p_img, settings.window_width);
	return (settings);
}

t_camera				init_camera(t_vec4 pos, t_vec4 focus)
{
	t_camera	cam;

	cam.pos = pos;
	cam.focus = focus;
	cam.zoom = 1.0f;
	cam.roll = 0.0f;
	return (cam);
}

void					set_rt_global_settings_ray_grid_props(
	t_global_settings *settings,
	t_camera *cam
)
{
	settings->cam = *cam;
	settings->ray_grid_props = get_ray_grid_properties(
		cam, settings->window_width, settings->window_height, M_PI / 2.0f);
}
