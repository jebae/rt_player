/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:30 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:06:34 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		event_camera_rotate(t_dispatcher *dispatcher)
{
	update_ray_grid_props(dispatcher->settings);
	render_by_mlx(dispatcher);
}

void			key_j(t_dispatcher *dispatcher)
{
	rotate_camera_pan(&(dispatcher->settings->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_l(t_dispatcher *dispatcher)
{
	rotate_camera_pan(&(dispatcher->settings->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_i(t_dispatcher *dispatcher)
{
	rotate_camera_tilt(&(dispatcher->settings->cam), 10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}

void			key_k(t_dispatcher *dispatcher)
{
	rotate_camera_tilt(&(dispatcher->settings->cam), -10.0f * DEGREE_1);
	event_camera_rotate(dispatcher);
}
