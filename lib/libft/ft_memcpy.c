/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:06 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 17:15:20 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	i = 0;
	if (!(void *)dst && !(void *)src)
		return (0);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned const char *) src;
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return ((void *) dst);
}
