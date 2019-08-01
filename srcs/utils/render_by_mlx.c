/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_by_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:14:01 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:14:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		render_by_mlx(t_dispatcher *dispatcher)
{
	render_scene(dispatcher->clkit, dispatcher->settings);
	mlx_put_image_to_window(
		dispatcher->p_mlx,
		dispatcher->p_win,
		dispatcher->p_img, 0, 0);
}
