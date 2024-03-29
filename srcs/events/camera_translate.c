/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:34 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:07:52 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		event_camera_translate(t_vec4 *v, t_dispatcher *dispatcher)
{
	t_mat4		mat;

	mat = camera_basis_mat(&(dispatcher->settings->cam));
	*v = mat_mul_vec(&mat, v);
	mat = translate_mat(v->arr[0], v->arr[1], v->arr[2]);
	camera_translate(&(dispatcher->settings->cam), &mat);
	update_ray_grid_props(dispatcher->settings);
	render_by_mlx(dispatcher);
}

void			key_a(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{-0.5f, 0.0f, 0.0f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void			key_d(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.5f, 0.0f, 0.0f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void			key_w(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.0f, 0.0f, 0.5f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void			key_s(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.0f, 0.0f, -0.5f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}
