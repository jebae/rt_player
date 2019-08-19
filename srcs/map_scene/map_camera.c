#include "rt_player.h"

void		map_camera(t_cam *cam_builder, t_global_settings *settings)
{
	settings->cam = init_camera(cam_builder->pos, cam_builder->focus);
}
