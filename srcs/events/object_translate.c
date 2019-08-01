/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:46 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:13:47 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

static void		event_object_translate(
	t_vec4 *v,
	t_dispatcher *dispatcher
)
{
	char		*objects_buf;
	t_mat4		mat;

	objects_buf = select_object(
		dispatcher->settings->objects_buf, dispatcher->object_index);
	mat = camera_basis_mat(&(dispatcher->settings->cam));
	*v = mat_mul_vec(&mat, v);
	mat = translate_mat(v->arr[0], v->arr[1], v->arr[2]);
	object_translate(objects_buf, &mat);
	render_by_mlx(dispatcher);
}

void			key_left(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{-0.5f, 0.0f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void			key_right(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.5f, 0.0f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void			key_up(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.0f, -0.5f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void			key_down(t_dispatcher *dispatcher)
{
	t_vec4				v;

	v = (t_vec4){{0.0f, 0.5f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}
