#include "rt_player.h"

int		map_scene(t_utils *parse_res, t_global_settings *settings)
{
	map_camera(&(parse_res->cam), settings);
	if (map_objects(
		parse_res->ob, parse_res->index, settings) == RTP_FAIL)
		return (RTP_FAIL);
	if (map_lights(
		parse_res->light, parse_res->light_index, settings) == RTP_FAIL)
		return (RTP_FAIL);
	return (RTP_SUCCESS);
}
