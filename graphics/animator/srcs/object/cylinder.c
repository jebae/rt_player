/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:11:06 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:12:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		cylinder_translate(char *objects_buf, t_mat4 *mat)
{
	t_cylinder		*cylinder;

	cylinder = (t_cylinder *)objects_buf;
	cylinder->c = mat_mul_vec(mat, &(cylinder->c));
}

void		cylinder_rotate(char *objects_buf, t_vec4 *n, float theta)
{
	t_cylinder		*cylinder;
	t_quaternion	q;
	t_quaternion	q_i;

	cylinder = (t_cylinder *)objects_buf;
	q = rotate_q(n, theta);
	q_i = inverse_q(&q);
	cylinder->v = rotate(&q, &(cylinder->v), &q_i);
}
