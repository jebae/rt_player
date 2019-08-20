/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:01:20 by jebae             #+#    #+#             */
/*   Updated: 2019/08/20 19:02:17 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t		new_triangle(t_objects *object, char *objects_buf)
{
	t_triangle			triangle;

	triangle.commons = object->att;
	triangle.commons.color = object->color;
	triangle.a = object->a;
	triangle.u = object->u;
	triangle.v = object->v;
	triangle.n = vec_cross_vec(&(triangle.u), &(triangle.v));
	triangle.n = normalize(&(triangle.n));
	write_mem_buf(objects_buf,
		(char *)&triangle, sizeof(triangle), RT_OBJECT_TYPE_TRIANGLE);
	return (sizeof(triangle) + sizeof(int));
}
