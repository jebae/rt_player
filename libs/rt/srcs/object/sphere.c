/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:01:10 by jebae             #+#    #+#             */
/*   Updated: 2019/08/20 18:43:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_sphere(t_objects *object, char *objects_buf)
{
	t_sphere			sphere;

	sphere.commons = object->att;
	sphere.commons.color = object->color;
	sphere.c = object->c;
	sphere.r = object->r;
	write_mem_buf(
		objects_buf, (char *)&sphere, sizeof(sphere), RT_OBJECT_TYPE_SPHERE);
	return (sizeof(sphere) + sizeof(int));
}
