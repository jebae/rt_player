/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:30:21 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:30:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		clear_all(t_dispatcher *dispatcher)
{
	release_clkit(dispatcher->clkit);
	clear_rt_settings(dispatcher->settings);
	mlx_destroy_image(dispatcher->p_mlx, dispatcher->p_img);
	mlx_destroy_window(dispatcher->p_mlx, dispatcher->p_win);
}
