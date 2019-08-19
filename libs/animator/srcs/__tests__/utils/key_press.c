#include "animator_test.h"

int		key_press(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		key_esc(param);
	else if (keycode == KEY_LEFT)
		key_left(param);
	else if (keycode == KEY_RIGHT)
		key_right(param);
	else if (keycode == KEY_UP)
		key_up(param);
	else if (keycode == KEY_DOWN)
		key_down(param);
	else if (keycode == KEY_A)
		key_a(param);
	else if (keycode == KEY_D)
		key_d(param);
	else if (keycode == KEY_W)
		key_w(param);
	else if (keycode == KEY_S)
		key_s(param);
	else if (keycode == KEY_COMMA)
		key_comma(param);
	else if (keycode == KEY_POINT)
		key_point(param);
	else if (keycode == KEY_J)
		key_j(param);
	else if (keycode == KEY_L)
		key_l(param);
	else if (keycode == KEY_I)
		key_i(param);
	else if (keycode == KEY_K)
		key_k(param);
	return (1);
}
