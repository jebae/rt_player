#include "rt_player.h"

char		*get_img_buffer(void *p_img, int width)
{
	static int		bpp = MLX_BPP;
	static int		endian = MLX_ENDIAN;

	return (mlx_get_data_addr(p_img, &bpp, &width, &endian));
}
