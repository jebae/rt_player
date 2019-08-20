/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:00:54 by jebae             #+#    #+#             */
/*   Updated: 2019/08/20 19:01:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_cone(t_objects *object, char *objects_buf)
{
	t_cone			cone;

	cone.commons = object->att;
	cone.commons.color = object->color;
	cone.theta = object->theta;
	cone.cos_2_theta = powf(cosf(cone.theta), 2);
	cone.h = object->h;
	cone.c = object->c;
	cone.v = normalize(&(object->v));
	write_mem_buf(
		objects_buf, (char *)&cone, sizeof(cone), RT_OBJECT_TYPE_CONE);
	return (sizeof(cone) + sizeof(int));
}
