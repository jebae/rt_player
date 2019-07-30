#include "rt_player.h"

void		render_by_mlx(t_dispatcher *dispatcher)
{
	render_scene(dispatcher->clkit, dispatcher->settings);
	mlx_put_image_to_window(
		dispatcher->p_mlx,
		dispatcher->p_win,
		dispatcher->p_img, 0, 0);
}
