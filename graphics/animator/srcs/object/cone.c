/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:03 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:11:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		cone_translate(char *objects_buf, t_mat4 *mat)
{
	t_cone		*cone;

	cone = (t_cone *)objects_buf;
	cone->c = mat_mul_vec(mat, &(cone->c));
}

void		cone_rotate(char *objects_buf, t_vec4 *n, float theta)
{
	t_cone			*cone;
	t_quaternion	q;
	t_quaternion	q_i;

	cone = (t_cone *)objects_buf;
	q = rotate_q(n, theta);
	q_i = inverse_q(&q);
	cone->v = rotate(&q, &(cone->v), &q_i);
}
