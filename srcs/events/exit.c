#include "rt_player.h"

void		key_esc(t_dispatcher *dispatcher)
{
	release(dispatcher->clkit);
	clear_global_settings(dispatcher->settings);
	mlx_destroy_image(dispatcher->p_mlx, dispatcher->p_img);
	mlx_destroy_window(dispatcher->p_mlx, dispatcher->p_win);
	exit(0);
}
