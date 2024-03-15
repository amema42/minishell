/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:28:59 by amema             #+#    #+#             */
/*   Updated: 2023/02/01 17:15:20 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && ft_strchr(set, s1[start]) != 0)
		start++;
	while (end >= start && ft_strchr(set, s1[end]) != 0)
		end--;
	result = (char *) malloc (sizeof(*s1) * (end - start + 2));
	if (!result)
		return (0);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = 0;
	return ((char *)result);
}
