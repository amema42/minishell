/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:40:36 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 18:41:06 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp_s1;
	size_t	i;

	tmp_s1 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tmp_s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp_s1[i] = s1[i];
		i++;
	}
	tmp_s1[i] = 0;
	return (tmp_s1);
}
