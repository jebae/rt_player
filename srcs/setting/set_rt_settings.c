#include "rt_player.h"

void	update_ray_grid_props(t_rt_settings *settings)
{
	settings->ray_grid_props = get_ray_grid_properties(
		&(settings->cam), 
		settings->window_width,
		settings->window_height,
		M_PI / 2.0f
	);
}

int		set_rt_settings(
	t_rt_settings *settings,
	t_dispatcher *dispatcher,
	t_utils *parse_res
)
{
	static t_vec4				i_a = (t_vec4){{0.07f, 0.07f, 0.07f, 1.0f}};
	t_init_rt_settings_args		args;

	args.parallel_mode = dispatcher->parallel_mode;
	args.width = WIDTH;
	args.height = HEIGHT;
	args.i_a = i_a;
	args.img_buf = (int *)get_img_buffer(
		dispatcher->p_img, args.width);
	init_rt_settings(settings, &args);
	if (map_scene(parse_res, settings) == RTP_FAIL)
		return (RTP_FAIL);
	update_ray_grid_props(settings);
	return (RTP_SUCCESS);
}

