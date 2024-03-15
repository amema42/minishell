/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:23:30 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 15:23:31 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

char	*find_end_command(char *position)
{
	char	*end_command;

	end_command = position + ft_strlen("$");
	while (*end_command != ' ' && *end_command != '\0'
		&& *end_command != '\"' && *end_command != '$'
		&& *end_command != '\'')
	{
		if (*end_command == '?')
		{
			if (*end_command + 1 == '\0')
				return (end_command + 2);
			else
				return (end_command + 1);
		}
		end_command++;
	}
	return (end_command);
}
