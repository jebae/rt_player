/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:28:55 by almoraru          #+#    #+#             */
/*   Updated: 2018/11/09 15:52:22 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = NULL;
	if (size)
	{
		ptr = malloc(size);
		if (ptr == NULL)
			return (NULL);
		else
			ft_bzero(ptr, size);
	}
	return (ptr);
}
