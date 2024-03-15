/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:28:29 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 18:28:32 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return ((void *) str);
}
