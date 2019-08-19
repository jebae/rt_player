#include "animator_test.h"

static void		event_object_translate(
	t_vec4 *v,
	t_test_dispatcher *dispatcher
)
{
	t_mat4	mat;

	mat = camera_basis_mat(&(dispatcher->cam));
	*v = mat_mul_vec(&mat, v);
	mat = translate_mat(v->arr[0], v->arr[1], v->arr[2]);
	object_translate(dispatcher->settings->objects_buf, &mat);
	event_render(dispatcher);
}

void			key_left(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{-0.5f, 0.0f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void		key_right(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.5f, 0.0f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void		key_up(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.0f, -0.5f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}

void		key_down(void *param)
{
	t_test_dispatcher	*dispatcher;
	t_vec4				v;

	dispatcher = (t_test_dispatcher *)param;
	v = (t_vec4){{0.0f, 0.5f, 0.0f, 1.0f}};
	event_object_translate(&v, dispatcher);
}
