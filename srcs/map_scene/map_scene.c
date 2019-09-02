/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:48:45 by jebae             #+#    #+#             */
/*   Updated: 2019/09/02 18:48:46 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

int		map_scene(t_utils *parse_res, t_global_settings *settings)
{
	map_camera(&(parse_res->cam), settings);
	if (map_objects(
		parse_res->ob, parse_res->i.object, settings) == RTP_FAIL)
		return (RTP_FAIL);
	if (map_lights(
		parse_res->light, parse_res->i.light, settings) == RTP_FAIL)
		return (RTP_FAIL);
	return (RTP_SUCCESS);
}
