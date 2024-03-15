/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:04:28 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 13:04:29 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

void	handle_pwd(void)
{
	char	current_directory[PATH_MAX];

	if (getcwd(current_directory, sizeof(current_directory)) != NULL)
		ft_printf("%s\n", current_directory);
	else
	{
		g_last_exit_status = 1;
		ft_putstr_fd("kitty shell: error while getting current directory\n", 2);
	}
}
