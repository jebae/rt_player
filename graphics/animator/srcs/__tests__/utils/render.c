#include "animator_test.h"

void		event_render(t_test_dispatcher *dispatcher)
{
	render_scene(dispatcher->clkit, dispatcher->settings);
	mlx_put_image_to_window(
		dispatcher->marker.p_mlx,
		dispatcher->marker.p_win,
		dispatcher->marker.p_img, 0, 0);
}
