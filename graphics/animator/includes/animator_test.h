#ifndef ANIMATOR_TEST_H
# define ANIMATOR_TEST_H

# include "animator.h"
# include "draw.h"

# define KEY_ESC						53
# define KEY_LEFT						123
# define KEY_RIGHT						124
# define KEY_UP							126
# define KEY_DOWN						125
# define KEY_A							0
# define KEY_S							1
# define KEY_D							2
# define KEY_W							13
# define KEY_LEFT_SQUARE_BRACKET		33
# define KEY_RIGHT_SQUARE_BRACKET		30
# define KEY_COMMA						43
# define KEY_POINT						47
# define KEY_J							38
# define KEY_L							37
# define KEY_I							34
# define KEY_K							40

typedef struct      s_test_dispatcher
{
	void                *p_mlx;
	void                *p_win;
	t_marker            marker;
	t_camera			cam;
	t_global_settings	*settings;
	t_clkit				*clkit;
}					t_test_dispatcher;

/*
** utils
*/
void				event_render(t_test_dispatcher *dispatcher);

char        		*get_img_buffer(void *p_img, int width);

void				init_marker(
	t_marker *marker,
	void *p_mlx,
	void *p_win,
	t_global_settings *settings
);

void				init_mlx(
	t_test_dispatcher *dispatcher,
	float width,
	float height
);

void				key_esc(void *param);

void				key_left(void *param);

void				key_right(void *param);

void				key_up(void *param);

void				key_down(void *param);

void				key_a(void *param);

void				key_d(void *param);

void				key_w(void *param);

void				key_s(void *param);

void				key_comma(void *param);

void				key_point(void *param);

void				key_l(void *param);

void				key_j(void *param);

void				key_i(void *param);

void				key_k(void *param);

int					key_press(int keycode, void *param);

/*
** tests
*/
void				test_sphere(int parallel_mode);

void				test_cylinder(int parallel_mode);

void				test_cone(int parallel_mode);

void				test_plane(int parallel_mode);

void				test_triangle(int parallel_mode);

void				test_camera(int parallel_mode);

void				test_scene1(int parallel_mode);

#endif
