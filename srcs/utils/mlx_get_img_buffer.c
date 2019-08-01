/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_img_buffer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:13:56 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 17:13:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

char		*get_img_buffer(void *p_img, int width)
{
	static int		bpp = MLX_BPP;
	static int		endian = MLX_ENDIAN;

	return (mlx_get_data_addr(p_img, &bpp, &width, &endian));
}
