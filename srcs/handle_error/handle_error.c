#include "rt_player.h"

int		rtp_print_err(const char *msg)
{
	put_color_str(KRED, msg);
	return (RTP_FAIL);
}

int		rtp_print_memalloc_err(const char *target)
{
    rtp_print_err("RTP : memalloc : Failed to allocate ");
    rtp_print_err(target);
    ft_putchar('\n');
    return (RTP_FAIL);
}
