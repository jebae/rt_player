/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:52:20 by jebae             #+#    #+#             */
/*   Updated: 2019/04/04 14:52:21 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*p_s1;

	p_s1 = s1;
	while (*p_s1 != '\0')
		p_s1++;
	while (*s2 != '\0' && n-- > 0)
		*(p_s1++) = *(s2++);
	*p_s1 = '\0';
	return (s1);
}
