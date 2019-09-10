/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:50 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:11:01 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		set_mlx(
	t_dispatcher *dispatcher,
	int width,
	int height
)
{
	dispatcher->p_mlx = mlx_init();
	dispatcher->p_win = mlx_new_window(
		dispatcher->p_mlx, width, height, "rt");
	mlx_key_hook(dispatcher->p_win, &key_press, dispatcher);
	mlx_hook(dispatcher->p_win,
		MLX_CLOSE_WINDOW, MLX_HOOK_MASK, &key_esc, dispatcher);
	dispatcher->p_img = mlx_new_image(
		dispatcher->p_mlx, width, height);
}
