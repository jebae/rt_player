/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:24 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 18:04:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		key_deep_trace_mode(int keycode, t_dispatcher *dispatcher)
{
	if (keycode == KEY_SPACE)
	{
		dispatcher->settings->deep_trace ^= 1;
		render_by_mlx(dispatcher);
		return (RTP_TRUE);
	}
	return (RTP_FALSE);
}
