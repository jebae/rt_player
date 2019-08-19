/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:08 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:09 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		object_rotate(char *objects_buf, t_vec4 *n, float theta)
{
	int		type;

	type = *((int *)objects_buf);
	if (type == RT_OBJECT_TYPE_CONE)
		cone_rotate(objects_buf + sizeof(int), n, theta);
	else if (type == RT_OBJECT_TYPE_CYLINDER)
		cylinder_rotate(objects_buf + sizeof(int), n, theta);
	else if (type == RT_OBJECT_TYPE_PLANE)
		plane_rotate(objects_buf + sizeof(int), n, theta);
	else if (type == RT_OBJECT_TYPE_TRIANGLE)
		triangle_rotate(objects_buf + sizeof(int), n, theta);
}
