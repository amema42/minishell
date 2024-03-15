/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:35:30 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 17:15:20 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*tmp_s1 && *tmp_s2 && *tmp_s1 == *tmp_s2 && n > 0)
	{
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	if (n > 0)
		return (*tmp_s1 - *tmp_s2);
	return (0);
}
