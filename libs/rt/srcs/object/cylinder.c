/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:00:57 by jebae             #+#    #+#             */
/*   Updated: 2019/08/19 13:39:58 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_cylinder(t_objects *object, char *objects_buf)
{
	t_cylinder			cylinder;

	cylinder.commons = object->att;
	cylinder.r = object->r;
	cylinder.h = object->h;
	cylinder.c = object->c;
	cylinder.v = normalize(&(object->v));
	write_mem_buf(objects_buf, (char *)&cylinder,
		sizeof(cylinder), RT_OBJECT_TYPE_CYLINDER);
	return (sizeof(cylinder) + sizeof(int));
}
