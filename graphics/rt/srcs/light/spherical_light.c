/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:00:51 by jebae             #+#    #+#             */
/*   Updated: 2019/08/19 16:12:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_spherical_light(t_lights *light, char *lights_buf)
{
	t_spherical_light		s_light;

	s_light.commons = light->att;
	s_light.origin = light->origin;
	write_mem_buf(
		lights_buf, (char *)&s_light, sizeof(s_light), RT_LIGHT_TYPE_SPHERICAL);
	return (sizeof(s_light) + sizeof(int));
}
