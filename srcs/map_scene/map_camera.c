/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:54 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 16:42:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		map_camera(t_cam *cam_builder, t_rt_settings *settings)
{
	settings->cam.pos = cam_builder->pos;
	settings->cam.zoom = 1.0f;
	settings->cam.roll = 0.0f;
	set_camera_axis(&(settings->cam), &(cam_builder->focus));
}
