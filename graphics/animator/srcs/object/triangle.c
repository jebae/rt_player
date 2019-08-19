/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:26 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:27 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		triangle_translate(char *objects_buf, t_mat4 *mat)
{
	t_triangle		*triangle;

	triangle = (t_triangle *)objects_buf;
	triangle->a = mat_mul_vec(mat, &(triangle->a));
}

void		triangle_rotate(char *objects_buf, t_vec4 *n, float theta)
{
	t_triangle		*triangle;
	t_quaternion	q;
	t_quaternion	q_i;

	triangle = (t_triangle *)objects_buf;
	q = rotate_q(n, theta);
	q_i = inverse_q(&q);
	triangle->n = rotate(&q, &(triangle->n), &q_i);
	triangle->u = rotate(&q, &(triangle->u), &q_i);
	triangle->v = rotate(&q, &(triangle->v), &q_i);
}
