#include "animator_test.h"

void		key_esc(void *param)
{
	t_test_dispatcher	*dispatcher;

	dispatcher = (t_test_dispatcher *)param;
	release(dispatcher->clkit);
	clear_global_settings(dispatcher->settings);
	mlx_destroy_image(dispatcher->p_mlx, dispatcher->marker.p_img);
	mlx_destroy_window(dispatcher->p_mlx, dispatcher->p_win);
	exit(0);
}
