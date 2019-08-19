/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:56:24 by almoraru          #+#    #+#             */
/*   Updated: 2018/11/10 18:07:50 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*tmp;
	unsigned char	tmp_char;

	tmp = (char *)b;
	tmp_char = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		tmp[i] = tmp_char;
		i++;
	}
	return (b);
}
