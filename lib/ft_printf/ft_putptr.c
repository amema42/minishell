/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:54:18 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 16:54:19 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(unsigned long long ptr, int i)
{
	if (ptr >= 16)
	{
		i++;
		i = ft_putptr_pf(ptr / 16, i);
	}
	ft_putchar_pf("0123456789abcdef"[ptr % 16]);
	return (i);
}
