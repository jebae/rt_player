/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:10:53 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:10:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animator.h"

void		rotate_camera_pan(t_camera *cam, float theta)
{
	static t_vec4		z_w = (t_vec4){{0.0f, 0.0f, 1.0f, 1.0f}};
	t_quaternion		q;
	t_quaternion		q_i;

	q = rotate_q(&z_w, theta);
	q_i = inverse_q(&q);
	if (ABS(vec_dot_vec(&z_w, &(cam->z_axis))) < 1.0f)
	{
		cam->z_axis = rotate(&q, &(cam->z_axis), &q_i);
		cam->z_axis = normalize(&(cam->z_axis));
	}
	if (ABS(vec_dot_vec(&z_w, &(cam->y_axis))) < 1.0f)
	{
		cam->y_axis = rotate(&q, &(cam->y_axis), &q_i);
		cam->y_axis = normalize(&(cam->y_axis));
	}
	cam->x_axis = rotate(&q, &(cam->x_axis), &q_i);
	cam->x_axis = normalize(&(cam->x_axis));
}

void		rotate_camera_tilt(t_camera *cam, float theta)
{
	t_quaternion	q;
	t_quaternion	q_i;

	q = rotate_q(&(cam->x_axis), theta);
	q_i = inverse_q(&q);
	cam->z_axis = rotate(&q, &(cam->z_axis), &q_i);
	cam->z_axis = normalize(&(cam->z_axis));
	set_camera_y_axis(cam);
}
