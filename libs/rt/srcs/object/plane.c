/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:01:04 by jebae             #+#    #+#             */
/*   Updated: 2019/08/19 13:39:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_plane(t_objects *object, char *objects_buf)
{
	t_plane				plane;

	plane.commons = object->att;
	plane.p = object->p;
	plane.n = normalize(&(object->n));
	write_mem_buf(
		objects_buf, (char *)&plane, sizeof(plane), RT_OBJECT_TYPE_PLANE);
	return (sizeof(plane) + sizeof(int));
}
