#include "rt_player.h"

int		key_select_object(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_LEFT_BRACKET)
	{
		key_left_bracket(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_RIGHT_BRACKET)
	{
		key_right_bracket(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}
