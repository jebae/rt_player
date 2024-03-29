/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_by_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:14:01 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:22:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		render_by_mlx(t_dispatcher *dispatcher)
{
	if (render_scene(
		dispatcher->clkit, dispatcher->settings) == RT_FAIL)
	{
		clear_all(dispatcher);
		exit(1);
	}
	mlx_put_image_to_window(
		dispatcher->p_mlx,
		dispatcher->p_win,
		dispatcher->p_img, 0, 0);
}
