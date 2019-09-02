/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:00:44 by jebae             #+#    #+#             */
/*   Updated: 2019/09/02 18:52:53 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_distant_light(t_lights *light, char *lights_buf)
{
	t_distant_light		dist_light;

	dist_light.commons = light->att;
	dist_light.d = normalize(&(light->d));
	write_mem_buf(
		lights_buf, (char *)&dist_light,
		sizeof(dist_light), RT_LIGHT_TYPE_DISTANT);
	return (sizeof(dist_light) + sizeof(int));
}
