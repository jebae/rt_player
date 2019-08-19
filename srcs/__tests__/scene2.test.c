#include "rt_player.h"

static float		WIDTH = 1000;
static float		HEIGHT = 800;

void				test_scene2(char *scene_src, int parallel_mode)
{
	t_dispatcher			dispatcher;
	t_clkit					clkit;
	t_global_settings		settings;
	t_utils					parse_res;

	ft_bzero(&parse_res, sizeof(parse_res));
	if (parse(&parse_res, scene_src))
		ft_error("Parsing failed!");

	dispatcher.parallel_mode = parallel_mode;
	dispatcher.settings = &settings;
	dispatcher.clkit = &clkit;
	dispatcher.object_index = 0;

	set_mlx(&dispatcher, WIDTH, HEIGHT);

	settings = init_rt_global_settings(&dispatcher, WIDTH, HEIGHT);
	if (map_scene(&parse_res, &settings) == RTP_FAIL)
		ft_error("Mapping scene failed!");
	set_rt_global_settings_ray_grid_props(&settings, &(settings.cam));

	init_clkit(&clkit, &settings);
	render_by_mlx(&dispatcher);
	mlx_loop(dispatcher.p_mlx);
}
