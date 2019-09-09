#include "rt_player.h"

void		clear_all(t_dispatcher *dispatcher)
{
	release_clkit(dispatcher->clkit);
	clear_rt_settings(dispatcher->settings);
	mlx_destroy_image(dispatcher->p_mlx, dispatcher->p_img);
	mlx_destroy_window(dispatcher->p_mlx, dispatcher->p_win);
}
