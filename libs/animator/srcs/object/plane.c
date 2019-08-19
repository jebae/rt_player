/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:20 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		plane_translate(char *objects_buf, t_mat4 *mat)
{
	t_plane		*plane;

	plane = (t_plane *)objects_buf;
	plane->p = mat_mul_vec(mat, &(plane->p));
}

void		plane_rotate(char *objects_buf, t_vec4 *n, float theta)
{
	t_plane			*plane;
	t_quaternion	q;
	t_quaternion	q_i;

	plane = (t_plane *)objects_buf;
	q = rotate_q(n, theta);
	q_i = inverse_q(&q);
	plane->n = rotate(&q, &(plane->n), &q_i);
}
