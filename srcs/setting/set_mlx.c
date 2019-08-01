/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:50 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:13:50 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		set_mlx(
	t_dispatcher *dispatcher,
	float width,
	float height
)
{
	dispatcher->p_mlx = mlx_init();
	dispatcher->p_win = mlx_new_window(
		dispatcher->p_mlx, (int)width, (int)height, "rt");
	mlx_key_hook(dispatcher->p_win, &key_press, dispatcher);
	dispatcher->p_img = mlx_new_image(
		dispatcher->p_mlx, (int)width, (int)height);
}
