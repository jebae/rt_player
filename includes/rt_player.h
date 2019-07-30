#ifndef RT_PLAYER_H
# define RT_PLAYER_H

# include <mlx.h>
# include <stdio.h> // this will be removed after
# include "rt.h"
# include "rt_args.h"
# include "rt_parallel.h"
# include "rt_struct.h"
# include "libft.h"
# include "gmath.h"
# include "clkit.h"
# include "animator.h"

# define RTP_TRUE						1
# define RTP_FALSE						0

# define MLX_BPP						32
# define MLX_ENDIAN						0

# define KEY_ESC						53
# define KEY_LEFT						123
# define KEY_RIGHT						124
# define KEY_UP							126
# define KEY_DOWN						125
# define KEY_A							0
# define KEY_S							1
# define KEY_D							2
# define KEY_W							13
# define KEY_COMMA						43
# define KEY_POINT						47
# define KEY_J							38
# define KEY_L							37
# define KEY_I							34
# define KEY_K							40

typedef struct			s_dispatcher
{
	int					parallel_mode;
	int					object_index;
    void				*p_mlx;
    void				*p_win;
    void				*p_img;
    t_global_settings	*settings;
    t_clkit				*clkit;
}						t_dispatcher;

/*
** events
*/
int						key_press(int keycode, void *param);

void					key_esc(t_dispatcher *dispatcher);

void					key_left(t_dispatcher *dispatcher);

void					key_right(t_dispatcher *dispatcher);

void					key_up(t_dispatcher *dispatcher);

void					key_down(t_dispatcher *dispatcher);

void					key_comma(t_dispatcher *dispatcher);

void					key_a(t_dispatcher *dispatcher);

void					key_d(t_dispatcher *dispatcher);

void					key_w(t_dispatcher *dispatcher);

void					key_s(t_dispatcher *dispatcher);

void					key_j(t_dispatcher *dispatcher);

void					key_l(t_dispatcher *dispatcher);

void					key_i(t_dispatcher *dispatcher);

void					key_k(t_dispatcher *dispatcher);

void					key_point(t_dispatcher *dispatcher);

/*
** setting
*/
void					set_mlx(
	t_dispatcher *dispatcher,
	float width,
	float height
);

t_global_settings		init_rt_global_settings(
	t_dispatcher *dispatcher,
	float width,
	float height
);

t_camera				init_camera(t_vec4 pos, t_vec4 focus);

void					set_rt_global_settings_ray_grid_props(
	t_global_settings *settings,
	t_camera *cam
);

/*
** utils
*/
void					render_by_mlx(t_dispatcher *dispatcher);

char					*get_img_buffer(void *p_img, int width);

/*
** test
*/
void					test_scene1(int parallel_mode);

#endif
