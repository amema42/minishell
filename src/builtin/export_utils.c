/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:04:10 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 13:40:37 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	is_accepted_variable(char *var)
{
	int	i;

	i = 1;
	if (!ft_isalpha(var[0]) && var[0] != '_')
		return (0);
	return (1);
}

int	len_equalchar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (str[i - 1] == '+')
		i--;
	return (i);
}

void	show_export_error(char *arg)
{
	g_last_exit_status = 1;
	ft_putstr_fd("kitty shell:", 2);
	ft_putstr_fd(" export: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}
