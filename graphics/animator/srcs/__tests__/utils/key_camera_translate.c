#include "animator_test.h"

static void		event_camera_translate(t_vec4 *v, t_test_dispatcher *dispatcher)
{
	t_mat4		mat;

	mat = camera_basis_mat(&(dispatcher->cam));
	*v = mat_mul_vec(&mat, v);
	mat = translate_mat(v->arr[0], v->arr[1], v->arr[2]);
	camera_translate(&(dispatcher->cam), &mat);
	dispatcher->settings->ray_grid_props = get_ray_grid_properties(
		&(dispatcher->cam),
		(float)(dispatcher->settings->window_width),
		(float)(dispatcher->settings->window_height),
		M_PI / 2.0f);
	event_render(dispatcher);
}

void			key_a(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{-0.5f, 0.0f, 0.0f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void		key_d(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.5f, 0.0f, 0.0f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void		key_w(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.0f, 0.0f, 0.5f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}

void		key_s(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.0f, 0.0f, -0.5f, 1.0f}};
	event_camera_translate(&v, dispatcher);
}
