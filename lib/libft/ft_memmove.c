/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:36:47 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 17:19:04 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	unsigned char		*tmp_src;
	size_t				i;

	i = 0;
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			((char *) dst)[i] = ((const char *) src)[i];
			i++;
		}
	}
	else
	{
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	return ((void *) dst);
}
