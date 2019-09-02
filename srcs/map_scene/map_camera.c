/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:54 by jebae             #+#    #+#             */
/*   Updated: 2019/09/02 18:46:55 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		map_camera(t_cam *cam_builder, t_global_settings *settings)
{
	settings->cam = init_camera(cam_builder->pos, cam_builder->focus);
}
