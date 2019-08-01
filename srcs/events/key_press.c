/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:39 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:17:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static int		key_object_translate(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_LEFT)
	{
		key_left(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_RIGHT)
	{
		key_right(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_UP)
	{
		key_up(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_DOWN)
	{
		key_down(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}

static int		key_object_rotate(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_COMMA)
	{
		key_comma(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_POINT)
	{
		key_point(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}

static int		key_camera_translate(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_A)
	{
		key_a(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_D)
	{
		key_d(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_W)
	{
		key_w(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_S)
	{
		key_s(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}

static int		key_camera_rotate(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_J)
	{
		key_j(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_L)
	{
		key_l(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_I)
	{
		key_i(dispatcher);
		return (RTP_TRUE);
	}
	else if (keycode == KEY_K)
	{
		key_k(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}

int				key_press(int keycode, void *param)
{
	t_dispatcher	*dispatcher;

	dispatcher = (t_dispatcher *)param;
	if (keycode == KEY_ESC)
		key_esc(dispatcher);
	else if (key_object_translate(keycode, dispatcher) == RTP_TRUE)
		return (1);
	else if (key_object_rotate(keycode, dispatcher) == RTP_TRUE)
		return (1);
	else if (key_camera_translate(keycode, dispatcher) == RTP_TRUE)
		return (1);
	else if (key_camera_rotate(keycode, dispatcher) == RTP_TRUE)
		return (1);
	return (1);
}
