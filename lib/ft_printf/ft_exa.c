/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:53:54 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 16:53:56 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_exa_pf(unsigned int nb, const char format, int i)
{
	if (nb >= 16)
	{
		i++;
		i = ft_exa_pf(nb / 16, format, i);
	}
	if (format == 'x')
		ft_putchar_pf("0123456789abcdef"[nb % 16]);
	if (format == 'X')
		ft_putchar_pf("0123456789ABCDEF"[nb % 16]);
	return (i);
}
