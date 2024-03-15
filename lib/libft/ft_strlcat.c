/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:20:49 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 18:47:31 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src && !dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (j != dstsize)
		dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
