/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:43 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:18:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		event_object_rotate(
	float theta,
	t_dispatcher *dispatcher
)
{
	char		*objects_buf;

	objects_buf = select_object(
		dispatcher->settings->objects_buf, dispatcher->object_index);
	object_rotate(objects_buf, &(dispatcher->settings->cam.z_axis), theta);
	render_by_mlx(dispatcher);
}

void			key_comma(t_dispatcher *dispatcher)
{
	event_object_rotate(10.0f * DEGREE_1, dispatcher);
}

void			key_point(t_dispatcher *dispatcher)
{
	event_object_rotate(-10.0f * DEGREE_1, dispatcher);
}
