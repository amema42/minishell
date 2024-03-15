/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env_n_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amema <amema@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:32:35 by amema             #+#    #+#             */
/*   Updated: 2024/03/15 13:42:01 by amema            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_shell.h"

int	my_setcontrol(char *environ, char *name, char *value)
{
	int	len;

	len = ft_strlen(name);
	if (ft_strncmp(environ, name, len) == 0 && value && (environ[len] == '='
			|| environ[len] == '\0'))
		return (0);
	if (ft_strncmp(environ, name, len) == 0 && !value && (environ[len] == '='
			|| environ[len] == '\0'))
		return (1);
	return (-1);
}

void	env_append(char **env_var, char ***environ, char *value, int index)
{
	if (ft_strchr((*environ)[index], '=') == NULL)
		*env_var = ft_strjoin((*environ)[index], &value[1]);
	else
		*env_var = ft_strjoin((*environ)[index], &value[2]);
	return ;
}

int	my_setenv(char *name, char *value, char ***environ)
{
	char	*env_var;
	int		index;

	env_var = NULL;
	index = -1;
	while ((*environ)[++index] != NULL)
	{
		if (my_setcontrol((*environ)[index], name, value) == 0)
		{
			if (value[0] == '+')
				env_append(&env_var, environ, value, index);
			else
				env_var = ft_strjoin(name, value);
			free((*environ)[index]);
			(*environ)[index] = env_var;
			return (0);
		}
		if (my_setcontrol((*environ)[index], name, value) == 1)
			return (index);
	}
	if (!value)
		return (-1);
	env_var = ft_strjoin(name, ft_strchr(value, '='));
	*environ = matrix_newline(*environ, env_var);
	return (0);
}
